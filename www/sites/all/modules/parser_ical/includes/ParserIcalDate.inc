<?php

/**
 * @file
 *  Classes for using date_api ical parsing.
 */

class ParserIcalDateModule extends ParserIcalFeeds {
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

    $feed_output = $fetcher_result->getRaw();
    $feed_folded = explode("\n", $feed_output);
    $parsed = date_ical_parse($feed_folded);
    $ical = $parsed[0];

    $result = new ParserIcalResult();

    $result->title = isset($ical['X-WR-CALNAME']) ? $ical['X-WR-CALNAME'] : '';
    $result->description = isset($ical['X-WR-CALDESC']) ? $ical['X-WR-CALDESC'] : '';
    $timezone = isset($ical['X-WR-TIMEZONE']) ? $ical['X-WR-TIMEZONE'] : '';
    if (! empty($timezone)) {
      try {
        $tz = new DateTimeZone($xprop[1]);
        $result->timezone = $tz;
      }
      catch (Exception $e) {
        $source->log('parse', 'Invalid X-WR-TIMEZONE: %error', array('%error' => $e->getMessage()), WATCHDOG_NOTICE);
      }
    }
    $components = array();
    if (isset($ical['VEVENT'])) {
      foreach ($ical['VEVENT'] as $event) {
        $components[] = new ParserIcalDateModuleComponent('vevent', $event);
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
   */
  public function formatText($property_key, $property, ParserIcalComponentInterface $item, FeedsParserResult $result, FeedsSource $source) {
    return $property;
  }
 
  /**
   * Load external iCalcreator class from libary.
   */
  static public function loadLibrary() {
    include_once(drupal_get_path('module', 'date_api') .'/date_api_ical.inc');
  }
}

/**
 * A wrapper on iCalcreator component class.
 */
class ParserIcalDateModuleComponent implements ParserIcalComponentInterface {
  protected $component;
  protected $type;

  public function __construct($type, $component) {
    $this->type = strtoupper($type);
    $this->component = $component;
  }

  public function getComponentType() {
    return $this->type;
  }

  public function setComponentType($type) {
    $this->type = strtoupper($type);
  }

  public function getProperty($name) {
    $name = strtoupper($name);
    return (isset($this->component[$name]) ? $this->component[$name] : NULL);
  }

  public function setProperty($name, $value) {
    $name = strtoupper($name);
    $this->component[$name] = $value;
  }  
}
