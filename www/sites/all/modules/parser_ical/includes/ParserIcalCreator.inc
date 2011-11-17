<?php

/**
 * @file
 *  Basic classes.
 */
class ParserIcalCreator extends ParserIcalFeeds {
  /**
   * Output sources this parser offers.
   *
   * Includes additional field for the handler for output.
   *
   * @see ParserIcalCreator::getMappingSources().
   * @see ParserIcalCreator::getSourceElement().
   */
  static protected $sources = array(
    'summary' => array(
      'name' => 'Summary',
      'description' => 'A short summary or subject for the calendar component.',
      'parser_ical_handler' => 'formatText',
    ),
    'description' => array(
      'name' => 'Description',
      'description' => 'A more complete description calendar component than that provided by the "summary" property.',
      'parser_ical_handler' => 'formatText',
    ),
    'dtstart' => array(
      'name' => 'Date start',
      'description' => 'Start time for the feed item.',
      'parser_ical_handler' => 'formatDateTime',
    ),
    'dtend' => array(
      'name' => 'Date end',
      'description' => 'End time for the feed item.',
      'parser_ical_handler' => 'formatDateTime',
    ),
  );

  /**
   * Load and run parser implementation of FeedsParser::parse().
   *
   * @params - change these to generic required paramters.
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    self::loadLibrary();

    // get the temporary file path
    $filename = $fetcher_result->getFilePath();

    //
    // create the parser and load results
    //
    $config = array(
      'unique_id' => '', // do we need one for incoming parsing?
      'url' => $filename, // it's a stream wrapper, so url
    );
    $parser = new vcalendar($config);
    if (! $parser->parse()) {
      throw new ParserIcalParseException(t('Error parsing %source iCal file %file', array('%source' => 'todo', '%file' => $filename)));
    }

    //
    // Set a result object.
    //
    $result = new ParserIcalResult();

    // FeedsResult properties
    $xprop = $parser->getProperty('X-WR-CALNAME');
    $result->title = (! empty($xprop) ? $xprop[1] : '');
    $xprop = $parser->getProperty('X-WR-CALDESC'); 
    $result->description = (! empty($xprop) ? $xprop[1] : '');
    $result->link = NULL;

    // additional ParserIcalResult() properties
    $xprop = $parser->getProperty('X-WR-TIMEZONE');
    if (! empty($xprop)) {
      try {
        $tz = new DateTimeZone($xprop[1]);
        $result->timezone = $tz;
      }
      catch (Exception $e) {
        $source->log('parse', 'Invalid X-WR-TIMEZONE: %error', array('%error' => $e->getMessage()), WATCHDOG_NOTICE);
      }
    }
    $components = array();
    while ($component = $parser->getComponent('TIMEZONE')) {
      $components[$component->getProperty('tzid')] = new ParserIcalCreatorComponent($component);
    }
    $result->timezones = $components;

    // feed items themselves
    $components = array();
    $component_types = array('vevent', 'vtodo', 'vjournal', 'vfreebusy', 'valarm'); // @todo: admin per feed configurable; check each makes sense.
    foreach ($component_types as $component_type) {
      while ($component = $parser->getComponent($component_type)) {
        $components[] = new ParserIcalCreatorComponent($component);
      }
    }
    $result->items = $components;

    return $result;
  }

  /******
   * Source output formatters.
   * 
   * Could be in a class of their own?
   **/

  /**
   * Format text fields.
   *
   * @todo is \n \N handling correct?
   */
  public function formatText($property_key, $property, ParserIcalComponentInterface $item, FeedsParserResult $result, FeedsSource $source) {
    $text = $property['value'];
    $text = str_replace(array("\\n", "\\N"), "\n", $text);
    return $text;
  }

  /**
   * Format date fields.
   *
   * @return FeedsDateTime
   */
  public function formatDateTime($property_key, $property, ParserIcalComponentInterface $item, ParserIcalResult $result, FeedsSource $source) {
    $d = $property['value'];

    if (isset($property['params']['VALUE']) && $property['params']['VALUE'] == 'DATE') {
      /** 
       * DATE are 'anniversary type' day events, no time set.
       * This can span over multiple days.
       * FeedsDateTime sets the granularity correctly.
       * However the granularity is not used yet.
       * All Day events handling is not finalized at the time of writing.
       * Multiple day all day events are not handled at this point.
       * http://drupal.org/node/874322 To Date & All Day Date Handling
       */
      if ($property_key == 'dtend') {
        $s = $item->getProperty('dtstart');
        $s = $s['value'];
        if ($s['year'] == $d['year'] && $s['month'] == $d['month'] && $s['day'] == $d['day'] - 1) {
          // Single day, all day event.
          // iCal DATE has start on day, end on next day.
          // Presently handled date.module by having same start and end dates.
          // See notes about timezone handling in issue above however.
          $d = $s;
        }
      }
      // order matters here dtstart has to come before dtend
      if ($property_key == 'dtstart') {
        if ($duration = $item->getProperty('duration')) {
          // @todo there is handling in the iCalcreator Utils
        }
        elseif (! $item->getProperty('dtend')) {   
          // For cases where a "VEVENT"+... calendar component
          // specifies a "DTSTART" property with a DATE value type but no
          // "DTEND" nor "DURATION" property, the event's duration is taken to
          // be one day.
          $item->setProperty('dtend', $property);
        }
      }
      $feeds_object = new FeedsDateTime($d['year'] . '-' . $d['month'] . '-' . $d['day']);
    }
    else {
      // Date with time.
      $date_string = iCalUtilityFunctions::_format_date_time($d);

      // If there was no timezone on the date string itself, 
      // add one if we have one.
      if (empty($d['tz'])) {
        if (! empty($property['params']['TZID'])) {
          // timezone on the iCal DATETIME
          try {
            $tz = new DateTimeZone($property['params']['TZID']);
            // note: these should relate to the ParserIcalResult::$timezones
            // but see comment on property
          }
          catch (Exception $e) {
            $source->log('parse', 'DATE-TIME TZID not in PHP timezonedb: %error', array('%error' => $e->getMessage()), WATCHDOG_NOTICE);
          }
        }
        elseif (! empty($result->timezone)) {
          // feed wide timezone
          $tz = $result->timezone;
        }
      }
      if (! (isset($tz) && is_a($tz, 'DateTimeZone'))) {
        $tz = NULL;
      }

      $feeds_object = new FeedsDateTime($date_string, $tz);
    }

    return $feeds_object;
  }

  /**
   * Load external iCalcreator class from libary.
   */
  static public function loadLibrary() {
    $creator_path = libraries_get_path('iCalcreator');
    require_once($creator_path . '/iCalcreator.class.php');
  }
}

class ParserIcalResult extends FeedsParserResult {
  // Feed extension timezone (X-WR-TIMEZONE)
  public $timezone;

  // Feed RFC 5545 timezones; we can't use these at
  // present, only PHP timezonedb tz will be actually recognized.
  // So this is more here as reminder/explanation.
  public $timezones;
}

/**
 * A wrapper on iCalcreator component class.
 */
class ParserIcalCreatorComponent implements ParserIcalComponentInterface {
  protected $component;
  private $_serialized_component;

  /**
   * Constructor.
   *
   * @param
   *   vcalendar object configured, but not parsed.
   */
  public function __construct($component) {
    $this->component = $component;
  }

  /**
   * Serialization helper.
   */
  public function __sleep() {
    $this->_serialized_component = serialize($this->component);
    return array('_serialized_component');
  }

  /**
   * Unserialization helper.
   */
  public function __wakeup() {
    ParserIcalCreator::loadLibrary();
    $this->component = unserialize($this->_serialized_component);
  }

  public function getComponentType() {
    return $this->getProperty('objName');
  }

  public function setComponentType($type) {
    return $this->setProperty('objName', $type);
  }

  public function getProperty($name) {
    return $this->component->getProperty($name, FALSE, TRUE);
  }

  public function setProperty($name, $value) {
    return $this->component->setProperty($name, $value);
  }
}

