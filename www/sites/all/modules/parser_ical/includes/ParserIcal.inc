<?php

/**
 * Basic classes.
 */

/**
 * Parent class for Feeds integration.
 */
abstract class ParserIcalFeeds extends FeedsParser {
  /**
   * The output sources the parser offers.
   * 
   * array(
   *  'feeds_output_key' => array(
   *    'name' => 'Human readable name of output source.',
   *    'description' => 'Longer description of source.',
   *    'parser_ical_handler' => 'Method callback for parsing source before handing to feeds.',
   *  ),
   * );
   */
  static protected $sources;

  /**
   * Implementation of FeedsParser::getMappingSources().
   */
  public function getMappingSources() {
    // Quirky work around. 
    // Want to have the sources as a property of the class,
    // but can't declare them with t(). 
    $sources = $this::$sources;
    foreach ($sources as $key => &$value) {
      if ($key == 'name' || $key == 'description') {
        $value = t($value);
      }
    }
    // parent::getMappingSources() triggers target creation too.
    return $sources + parent::getMappingSources();
  } 

  /**
   * Override FeedsParser::getSourceElement().
   */
  public function getSourceElement(FeedsSource $source, FeedsParserResult $result, $property_key) {
    // Allow parent method to handle any mappings based on the parent node.
    if (substr($property_key, 0, 7) == 'parent:') {
      return parent::getSourceElement($source, $result, $property_key);
    }

    // Otherwise retrieve the current ParserIcalCreatorComponent 
    // from the ParserIcalResult
    if ($item = $result->currentItem()) {
      // and use listed handler to get source output
      $handler = $this::$sources[$property_key]['parser_ical_handler'];
      $property = $item->getProperty($property_key);
      return $this->$handler($property_key, $property, $item, $result, $source);
    }
  }
}

interface ParserIcalComponentInterface {
  public function getComponentType();
  public function setComponentType($type);
  public function setProperty($name, $value);
  public function getProperty($name);
}

/**
 * Generic ParserIcal exceptions.
 */
class ParserIcalException extends Exception {}

/**
 * ParserIcal failed to parse some part of iCal.
 */
class ParserIcalParseException extends ParserIcalException {}

