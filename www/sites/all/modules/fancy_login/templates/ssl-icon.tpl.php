<?php // $Id: ssl-icon.tpl.php,v 1.3 2011/01/25 08:41:24 hakulicious Exp $ ?>
<div id="ssl_icon">
	<img src="<?php print $variables['base_url'] . '/' . drupal_get_path('module', 'fancy_login'); ?>/images/https.png" alt="<?php print t('Secure Login'); ?>" title="<?php print t('This login is SSL protected'); ?>" id="ssl_login_image" />
	<div id="ssl_login_popup">
		<p>This login is SSL protected</p>
	</div>
</div>
