<?php
/**
 * $title
 *   The name of the calendar.
 */

?>
BEGIN:VCALENDAR
VERSION:2.0
METHOD:PUBLISH
X-WR-CALNAME: <?php print $title . "\r\n"; ?>
PRODID:-//Drupal iCal API//EN
<?php print $rows ?>
END:VCALENDAR
