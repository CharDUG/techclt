<?php

/**
 * @file
 * This file contains all codecs provided by Video Filter.
 */

function video_filter_codec_info() {
  $codecs = array();

  $codecs['youtube'] = array(
    'name' => t('YouTube'),
    'sample_url' => 'http://www.youtube.com/watch?v=uN1qUeId',
    'callback' => 'video_filter_youtube',
    'html5_callback' => 'video_filter_youtube_html5',
    'regexp' => array(
                  '/youtube\.com\/watch\?v=([a-z0-9\-_]+)/i',
                  '/youtu.be\/([a-z0-9\-_]+)/i',
                  '/youtube\.com\/v\/([a-z0-9\-_]+)/i',
                ),
    'ratio' => 16 / 9,
    'control_bar_height' => 25,
  );
  $codecs['google'] = array(
    'name' => t('Google Video'),
    'sample_url' => 'http://video.google.com/videoplay?docid=-uN1qUeId',
    'callback' => 'video_filter_google',
    'regexp' => '/video\.google\.[a-z]+\.?[a-z]+?\/videoplay\?docid=(\-?[0-9]+)/',
    'ratio' => 400 / 326,
  );
  $codecs['tangle'] = array(
    'name' => t('Tangle'),
    'sample_url' => 'http://www.tangle.com/view_video?viewkey=b2e45d2a30cb0f5cad38',
    'callback' => 'video_filter_tangle',
    'regexp' => array(
                  '/tangle\.com\/view_video\.php\?viewkey=([a-z0-9]+)/',
                  '/tangle\.com\/view_video\?viewkey=([a-z0-9]+)/',
                ),
    'ratio' => 330 / 270,
  );
  $codecs['dailymotion'] = array(
    'name' => t('DailyMotion'),
    'sample_url' => 'http://www.dailymotion.com/video/some_video_title',
    'callback' => 'video_filter_dailymotion',
    'regexp' => '/dailymotion\.com\/video\/([a-z0-9\-_]+)/i',
    'ratio' => 4 / 3,
    'control_bar_height' => 20,
  );
  $codecs['vimeo'] = array(
    'name' => t('Vimeo'),
    'sample_url' => 'http://www.vimeo.com/123456',
    'callback' => 'video_filter_vimeo',
    'html5_callback' => 'video_filter_vimeo_html5',
    'regexp' => '/vimeo\.com\/([0-9]+)/',
    'ratio' => 16 / 9,
    'control_bar_height' => 0,
  );
  $codecs['flickr_slideshows'] = array(
    'name' => t('Flickr Slideshows'),
    'sample_url' => 'http://www.flickr.com/photos/username/sets/1234567890/show/',
    'callback' => 'video_filter_flickr_slideshows',
    'regexp' => '/flickr\.com\/photos\/([a-zA-Z0-9@_\-]+)\/sets\/([0-9]+)\/?[show]?\/?/i',
    'ratio' => 4 / 3,
    'control_bar_height' => 0,
  );
  $codecs['flickr_video'] = array(
    'name' => t('Flickr Video'),
    'sample_url' => 'http://www.flickr.com/photos/hansnilsson/1234567890/',
    'callback' => 'video_filter_flickr_video',
    'regexp' => '/flickr\.com\/photos\/([a-zA-Z0-9@_\-]+)\/([0-9]+)/',
    'ratio' => 4 / 3,
    'control_bar_height' => 0,
  );
  $codecs['gamevideos'] = array(
    'name' => t('Game Videos'),
    'sample_url' => 'http://gamevideos.1up.com/video/id/12345',
    'callback' => 'video_filter_gamevideos',
    'regexp' => '/gamevideos\.1up\.com\/video\/id\/([0-9]+)/',
    'ratio' => 500 / 319,
  );
  $codecs['metacafe'] = array(
    'name' => t('Meta Cafe'),
    'sample_url' => 'http://www.metacafe.com/watch/1234567890/some_title/',
    'callback' => 'video_filter_metacafe',
    'regexp' => '/metacafe\.com\/watch\/([a-z0-9\-_]+)\/([a-z0-9\-_]+)/i',
    'ratio' => 400 / 313,
    'control_bar_height' => 32,
  );
  $codecs['streamhoster'] = array(
    'name' => t('Streamhoster'),
    'sample_url' => 'http://web26.streamhoster.com/username/filename.flv',
    'callback' => 'video_filter_streamhoster',
    'regexp' => '/([a-z0-9]+)\:\/\/([a-z0-9\-_]+)\.streamhoster\.com\/([a-z0-9\-_]+)\/([a-z0-9\-_\.]+)/i',
    'ratio' => 480 / 360,
  );
  $codecs['gametrailers'] = array(
    'name' => t('Game Trailers'),
    'sample_url' => 'http://www.gametrailers.com/video/some-title/12345',
    'callback' => 'video_filter_gametrailers',
    'regexp' => array(
      '/gametrailers\.com\/player\/([0-9]+)/',
      '/gametrailers\.com\/video\/([a-z0-9\-_]+)\/([0-9]+)/',
    ),
    'ratio' => 480 / 392,
  );
  $codecs['collegehumor'] = array(
    'name' => t('College Humor'),
    'sample_url' => 'http://www.collegehumor.com/video:1234567890',
    'callback' => 'video_filter_collegehumor',
    'regexp' => '/collegehumor\.com\/video\:([0-9]+)/',
    'ratio' => 16 / 9,
    'control_bar_height' => 0,
  );
  $codecs['myspace'] = array(
    'name' => t('MySpace'),
    'sample_url' => 'http://myspace.com/video/vid/1234567890',
    'callback' => 'video_filter_myspace',
    'regexp' => array(
      '/vids\.myspace\.com\/.*VideoID=([0-9]+)/i',
      '/myspace\.com\/video\/([a-z])+\/([0-9]+)/i',
      '/myspace\.com\/video\/([a-z0-9\-_]+)\/([a-z0-9\-_]+)\/([a-z0-9]+)/i',
      '/myspace\.com\/([a-z0-9\-_]+)\/videos\/([a-z0-9\-_]+)\/([a-z0-9]+)/i',
    ),
    'ratio' => 620 / 400,
    'control_bar_height' => 40,
  );
  $codecs['capped'] = array(
    'name' => t('Capped'),
    'sample_url' => 'http://capped.tv/playeralt.php?vid=some-title',
    'callback' => 'video_filter_capped',
    'regexp' => '/capped\.tv\/([a-zA-Z0-9\-_]+)/',
    'ratio' => 425 / 355,
  );
  $codecs['bliptv'] = array(
    'name' => t('Blip.tv'),
    'sample_url' => 'http://blip.tv/file/123456',
    'callback' => 'video_filter_bliptv',
    'regexp' => array(
                  '@blip\.tv/rss/flash/([^"\&\?/]+)@i',
                  '@blip\.tv/file/view/([^"\&\?/]+)@i',
                  '@blip\.tv/file/([^"\&\?/]+)@i',
                  '@blip\.tv/play/([^"\&\?/]+)@i',
                ),
    'ratio' => 16 / 9,
    'control_bar_height' => 30,
  );
  $codecs['slideshare'] = array(
    'name' => t('Slideshare'),
    'sample_url' => 'http://slideshare.net/?id=1759622&amp;doc=usingdrupal-090723103440-phpapp01',
    'callback' => 'video_filter_slideshare',
    'instructions' => t('You need to construct your own URL, using the "Wordpress Embed" code from Slideshare, extract the "id" and "doc" parts, and form the URL like this: slideshare.net/?id=1759622&amp;doc=usingdrupal-090723103440-phpapp01.'),
    'regexp' => '/slideshare\.net\/\?id=([a-z0-9]+).*doc=([a-z0-9-]+)/',
    'ratio' => 425 / 320,
    'control_bar_height' => 38,
  );
  $codecs['picasa_slideshows'] = array(
    'name' => t('Picasa Slideshows'),
    'sample_url' => 'http://picasaweb.google.com/data/feed/base/user/USER_NAME/albumid/5568104935784209834?alt=rss&amp;kind=photo&amp;hl=en_US',
    'callback' => 'video_filter_picasa_slideshows',
    'instructions' => t('You must use the URL of the RSS feed for the Picasa album:') .
                      '<ol>' .
                      '<li>' . t('View the album in Picasa (you should see thumbnails, not a slideshow).') . '</li>' .
                      '<li>' . t('Find the "RSS" link and click it.') . '</li>' .
                      '<li>' . t('Copy the resulting URL from the browser address bar.  Example: ') . '<br />' .
                      '<code>[video: http://picasaweb.google.com/data/feed/base/user/USER_NAME/albumid/5568104935784209834?alt=rss&amp;kind=photo&amp;hl=en_US]</code>' .
                      '</li>' .
                      '</ol>',
    'regexp' => '/picasaweb\.google\.com\/data\/feed\/base\/user\/([a-zA-Z0-9@_\-]+)\/albumid\/([a-z0-9]+)/i',
    'ratio' => 800 / 600,
  );

  $codecs['teachertube'] = array(
    'name' => t('Teachertube'),
    'sample_url' => 'http://www.teachertube.com/viewVideo.php?video_id=VIDEOID',
    'callback' => 'video_filter_teachertube',
    'regexp' => '/teachertube\.com\/viewVideo.php\?video_id\=([0-9]+)/i',
    'ratio' => 16 / 9,
  );

  return $codecs;
}

function video_filter_youtube($video) {
  $attributes = array(
    'rel' => $video['related'] ? 'rel=1' : 'rel=0',
    'autoplay' => $video['autoplay'] ? 'autoplay=1' : 'autoplay=0',
    'fs' => 'fs=1',
  );

  $video['source'] = 'http://www.youtube.com/v/' . $video['codec']['matches'][1] . '?' . implode('&amp;', $attributes);

  return video_filter_flash($video);
}

function video_filter_youtube_html5($video) {
  $attributes = array(
    'rel' => $video['related'] ? 'rel=1' : 'rel=0',
    'autoplay' => $video['autoplay'] ? 'autoplay=1' : 'autoplay=0',
  );
  $url = $video['codec']['matches'][1] . '?' . "wmode=transparent&amp;" . implode('&amp;', $attributes);
  $html = '<iframe src="http://www.youtube.com/embed/'.$url.'" width="'.$video['width'].'" height="'.$video['height'].'" frameborder="0"></iframe>';

  return $html;
}

function video_filter_google($video) {
  $video['source'] = 'http://video.google.com/googleplayer.swf?docId='.$video['codec']['matches'][1];

  return video_filter_flash($video);
}

function video_filter_tangle($video) {
  $video['source'] = 'http://www.tangle.com/flash/swf/flvplayer.swf?viewkey='.$video['codec']['matches'][1];

  return video_filter_flash($video);
}

function video_filter_dailymotion($video) {
  $video['source'] = 'http://www.dailymotion.com/swf/'.$video['codec']['matches'][1];

  return video_filter_flash($video);
}

function video_filter_vimeo($video) {
  $video['source'] = 'http://www.vimeo.com/moogaloop.swf?clip_id='.$video['codec']['matches'][1].'&amp;server=www.vimeo.com&amp;fullscreen=1&amp;show_title=1&amp;show_byline=1&amp;show_portrait=0&amp;color=&amp;autoplay='.$video['autoplay'];

  return video_filter_flash($video);
}

function video_filter_vimeo_html5($video) {
  $html = '<iframe src="http://player.vimeo.com/video/'.$video['codec']['matches'][1].($video['autoplay'] ? '?autoplay=1' : '').'" width="'.$video['width'].'" height="'.$video['height'].'" frameborder="0"></iframe>';

  return $html;
}

function video_filter_flickr_slideshows($video) {
  $slideshow_player_url = 'http://www.flickr.com/apps/slideshow/show.swf?v=67348';
  $video['source'] = $slideshow_player_url . ($video['autoplay'] ? '&amp;autoplay=1' : '');

  $user_name = $video['codec']['matches'][1];
  $set_id = $video['codec']['matches'][2];

  $params['flashvars'] = "&amp;offsite=true&amp;lang=en-us&amp;page_show_url=%2Fphotos%2F$user_name%2Fsets%2F$set_id%2Fshow%2F&amp;page_show_back_url=%2Fphotos%2F$user_name%2Fsets%2F$set_id%2F&amp;set_id=$set_id&amp;jump_to=";

  return video_filter_flash($video, $params);
}

function video_filter_flickr_video($video) {
  $video['source'] = 'http://www.flickr.com/apps/video/stewart.swf?v=1.161';

  $params['flashvars'] = '&amp;photo_id='.$video['codec']['matches'][2].'&amp;flickr_show_info_box=true';

  return video_filter_flash($video, $params);
}

function video_filter_gamevideos($video) {
  $video['source'] = 'http://gamevideos.1up.com/swf/gamevideos12.swf?embedded=1&amp;fullscreen=1&amp;autoplay=0&amp;src=http://gamevideos.1up.com/do/videoListXML%3Fid%3D'.$video['codec']['matches'][1];

  return video_filter_flash($video);
}

function video_filter_metacafe($video) {
  $video['source'] = 'http://metacafe.com/fplayer/'.$video['codec']['matches'][1].'/'.$video['codec']['matches'][2].'.swf';

  return video_filter_flash($video);
}

function video_filter_streamhoster($video) {
  $video['source'] = 'http://public.streamhoster.com/Resources/Flash/JWFLVMediaPlayer/mediaplayer.swf';

  $params = array('allowscriptaccess' => 'always');
  $protocol = $video['codec']['matches'][1];

  if ($protocol == 'rtmp') {
    $params['flashvars'] = 'file=' . urlencode('/' . $video['codec']['matches'][4]);
    $params['flashvars'] .= '&amp;streamer=' . urlencode('rtmp://' . $video['codec']['matches'][2] . '.streamhoster.com/' . $video['codec']['matches'][3]);
    $params['flashvars'] .= '&amp;type=rtmp';
  }
  elseif ($protocol == 'http') {
    $params[flashvars] = 'file=' . urlencode('http://' . $video['codec']['matches'][2] . '.streamhoster.com/' . $video['codec']['matches'][3] . '/' . $video['codec']['matches'][4]);
    $params['flashvars'] .= '&amp;type=video';
  }

  $params['flashvars'] .= '&amp;width=' . $video['width'] ;
  $params['flashvars'] .= '&amp;height=' . $video['height'] ;
  $params['flashvars'] .= !empty($video['autoplay']) ? '&amp;autostart=true' : '&amp;autostart=false';

  return video_filter_flash($video, $params);
}

function video_filter_gametrailers($video) {
  if (is_numeric($video['codec']['matches'][1])) {
    $match = $video['codec']['matches'][1];
  }
  elseif (is_numeric($video['codec']['matches'][2])) {
    $match = $video['codec']['matches'][2];
  }
  $video['source'] = 'http://www.gametrailers.com/remote_wrap.php?mid='.$match;

  return video_filter_flash($video, $params);
}

function video_filter_collegehumor($video) {
  $video['source'] = 'http://www.collegehumor.com/moogaloop/moogaloop.swf?clip_id='.$video['codec']['matches'][1].'&amp;fullscreen=1';

  return video_filter_flash($video);
}

function video_filter_myspace($video) {
  // The last match is the ID we need.
  $last = count($video['codec']['matches']);
  $video['source'] = 'http://mediaservices.myspace.com/services/media/embed.aspx/m='.$video['codec']['matches'][$last-1];

  return video_filter_flash($video, $params);
}

function video_filter_capped($video) {
  $video['source'] = 'http://capped.micksam7.com/playeralt.swf?vid='.$video['codec']['matches'][1];

  return video_filter_flash($video);
}

function video_filter_bliptv($video) {
  $id = $video['codec']['matches'][1];

  // Since video ID in URL is different than in embed code, use API
  // to lookup the embed code video ID. Adapted from emfield.module.
  $result = drupal_http_request('http://blip.tv/file/' . $id . '?skin=api');

  if ($result->code == 200) {
    $parser = drupal_xml_parser_create($result->data);
    $vals = array();
    $index = array();
    xml_parse_into_struct($parser, $result->data, $vals, $index);
    xml_parser_free($parser);
  
    $response = array();
    $response['_emfield_arghash'] = $arghash;
    $level = array();
    $start_level = 1;
    foreach ($vals as $xml_elem) {
      if ($xml_elem['type'] == 'open') {
        if (array_key_exists('attributes', $xml_elem)) {
          list($level[$xml_elem['level']], $extra) = array_values($xml_elem['attributes']);
        }
        else {
          $level[$xml_elem['level']] = $xml_elem['tag'];
        }
      }
      if ($xml_elem['type'] == 'complete') {
        $php_stmt = '$response';
        while ($start_level < $xml_elem['level']) {
          $php_stmt .= '[$level['. $start_level .']]';
          $start_level++;
        }
        $php_stmt .= '[$xml_elem[\'tag\']][] = $xml_elem[\'value\'];'. $php_stmt .'[$xml_elem[\'tag\']][] = $xml_elem[\'attributes\'];';
        eval($php_stmt);
        $start_level--;
      }
    }
    $id = $response['EMBEDLOOKUP'][0];
    // Protect from XSS.
    if (preg_match("/[^A-Za-z0-9]/", $id, $matches)) {
      watchdog('Video Filter', t('A faulty Blip.tv ID has been detected.'));
      $id = 0;
    }
  }
  
  $video['source'] = 'http://blip.tv/play/' . $id;
  $params = array(
    'allowscriptaccess' => 'always',
  );
  
  return video_filter_flash($video, $params);
}

function video_filter_slideshare($video) {
  $video['source'] = 'http://static.slideshare.net/swf/ssplayer2.swf?id=' . $video['codec']['matches'][1] . '&amp;doc=' . ($video['codec']['matches'][2]);

  return video_filter_flash($video);
}

function video_filter_picasa_slideshows($video) {
  $video['source'] = 'http://picasaweb.google.com/s/c/bin/slideshow.swf';

  $user_name = $video['codec']['matches'][1];
  $set_id = $video['codec']['matches'][2];

  $params['flashvars'] = "host=picasaweb.google.com&amp;&amp;feat=flashalbum&amp;RGB=0x000000&amp;feed=http%3A%2F%2Fpicasaweb.google.com%2Fdata%2Ffeed%2Fapi%2Fuser%2F" . $user_name . "%2Falbumid%2F" . $set_id . "%3Falt%3Drss%26kind%3Dphoto%26" . ($video['autoplay'] ? '' : '&amp;noautoplay=1');

  return video_filter_flash($video, $params);
}

function video_filter_teachertube($video) {
  $video['source'] = 'http://www.teachertube.com/embed/player.swf';

  $params['flashvars'] = 'file=http://www.teachertube.com/embedFLV.php?pg=video_'.$video['codec']['matches'][1].'&amp;menu=false&amp;frontcolor=ffffff&amp;lightcolor=FF0000&amp;logo=http://www.teachertube.com/www3/images/greylogo.swf&amp;skin=http://www.teachertube.com/embed/overlay.swf&amp;volume=80&amp;controlbar=over&amp;displayclick=link&amp;viral.link=http://www.teachertube.com/viewVideo.php?video_id='.$video['codec']['matches'][1].'&amp;stretching=exactfit&amp;plugins=viral-2&amp;viral.callout=none&amp;viral.onpause=false';

  return video_filter_flash($video, $params);
}
