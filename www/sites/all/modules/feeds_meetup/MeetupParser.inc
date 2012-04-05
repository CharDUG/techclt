<?php

/**
 * Class definition for Meetup RSS Parser.
 *
 * Parses Meetup RSS feeds.
 */
class MeetupParser extends FeedsParser {

  /**
   * Implements FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    feeds_include_library('common_syndication_parser.inc', 'common_syndication_parser');
    $feed = common_syndication_parser_parse($fetcher_result->getRaw());
    $result = new FeedsParserResult();
    $result->title = $feed['title'];
    $result->description = $feed['description'];
	
	// get date from description
	$timestamp_from_description = $feed['description'];
	preg_match('(January|February|March|April|May|June|July|August|September|October|November|December) \d{1,2} at \d{1,2}:\d{2} (AM|PM)',
	    $timestamp_from_description, $matches);
	$timestamp_from_description = $matches[0];
	
	// convert to unix timestamp
	$timestamp_from_description = strtotime(ereg_replace("at", date("Y"), $timestamp_from_description));
	
    $result->timestamp = $timestamp_from_description;
	
    $result->link = $feed['link'];
    if (is_array($feed['items'])) {
      foreach ($feed['items'] as $item) {
        if (isset($item['geolocations'])) {
          foreach ($item['geolocations'] as $k => $v) {
            $item['geolocations'][$k] = new FeedsGeoTermElement($v);
          }
        }
        $result->items[] = $item;
      }
    }
    return $result;
  }

  /**
   * Return mapping sources.
   *
   * At a future point, we could expose data type information here,
   * storage systems like Data module could use this information to store
   * parsed data automatically in fields with a correct field type.
   */
  public function getMappingSources() {
    return array(
      'title' => array(
        'name' => t('Title'),
        'description' => t('Title of the feed item.'),
      ),
      'description' => array(
        'name' => t('Description'),
        'description' => t('Description of the feed item.'),
      ),
      'author_name' => array(
        'name' => t('Author name'),
        'description' => t('Name of the feed item\'s author.'),
      ),
      'timestamp' => array(
         'name' => t('Parsed Meetup Event date'),
         'description' => t('Event date as UNIX time GMT, parsed from the description.'),
      ),
      'url' => array(
        'name' => t('Item URL (link)'),
        'description' => t('URL of the feed item.'),
      ),
      'guid' => array(
        'name' => t('Item GUID'),
        'description' => t('Global Unique Identifier of the feed item.'),
      ),
      'tags' => array(
        'name' => t('Categories'),
        'description' => t('An array of categories that have been assigned to the feed item.'),
      ),
      'geolocations' => array(
        'name' => t('Geo Locations'),
        'description' => t('An array of geographic locations with a name and a position.'),
      ),
     ) + parent::getMappingSources();
  }
}
