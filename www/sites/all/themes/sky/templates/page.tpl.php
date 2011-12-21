<div id="page" class="container">

  <?php print render($page['top_menu']); ?>

  <header class="clearfix" role="banner">

    <div id="branding">
      <?php if ($site_name || $site_slogan): ?>
        <hgroup<?php if (!$site_slogan && $hide_site_name): ?> class="<?php print $visibility; ?>"<?php endif; ?>>
          <?php if ($site_name): ?>
            <h1 id="site-name"<?php if ($hide_site_name): ?> class="<?php print $visibility; ?>"<?php endif; ?>><?php print $site_name; ?></h1>
          <?php endif; ?>
          <?php if ($site_slogan): ?>
            <h2 id="site-slogan"><?php print $site_slogan; ?></h2>
          <?php endif; ?>
        </hgroup>
      <?php endif; ?>
      <?php if ($linked_site_logo): ?>
        <div id="logo"><?php print $linked_site_logo; ?></div>
      <?php endif; ?>
    </div>

    <?php print render($page['header']); ?>
    <?php print render($page['menu_bar']); ?>

  </header>

  <div id="columns"<?php print $page['menu_bar'] ? 'class="no-menu-bar"' : '' ;?>><div class="columns-inner clearfix">

    <?php print $messages; ?>
    <?php print render($page['help']); ?>
    <?php print render($page['secondary_content']); ?>

    <?php if ($breadcrumb): ?>
      <section id="breadcrumb"><?php print $breadcrumb; ?></section>
    <?php endif; ?>

    <div id="content-column"><div class="content-inner">

      <?php print render($page['highlighted']); ?>

      <?php $tag = $title ? 'section' : 'div'; ?>
      <<?php print $tag; ?> id="main-content" role="main">

        <?php print render($title_prefix); ?>
        <?php if ($title && !isset($node)): ?>
          <header>
            <h1 id="page-title"><?php print $title; ?></h1>
          </header>
        <?php endif; ?>
        <?php print render($title_suffix); ?>

        <?php if ($primary_local_tasks || $secondary_local_tasks || $action_links): ?>
          <div id="tasks" class="clearfix">
            <?php if ($primary_local_tasks): ?>
              <ul class="tabs primary clearfix"><?php print render($primary_local_tasks); ?></ul>
            <?php endif; ?>
            <?php if ($secondary_local_tasks): ?>
              <ul class="tabs secondary clearfix"><?php print render($secondary_local_tasks); ?></ul>
            <?php endif; ?>
            <?php if ($action_links = render($action_links)): ?>
              <ul class="action-links clearfix"><?php print $action_links; ?></ul>
            <?php endif; ?>
          </div>
        <?php endif; ?>

        <div id="content"><?php print render($page['content']); ?></div>

        <?php print $feed_icons; ?>

      </<?php print $tag; ?>>

      <?php print render($page['content_aside']); ?>

    </div></div>

    <?php print render($page['sidebar_first']); ?>
    <?php print render($page['sidebar_second']); ?>
    <?php print render($page['tertiary_content']); ?>

  </div></div>

  <?php if ($page['footer'] || $page['four_first'] || $page['four_second'] || $page['four_third'] || $page['four_fourth']): ?>
    <footer role="contentinfo">
      <?php if ($page['four_first'] || $page['four_second'] || $page['four_third'] || $page['four_fourth']): ?>
        <div class="four-4x25 gpanel clearfix">
          <?php print render($page['four_first']); ?>
          <?php print render($page['four_second']); ?>
          <?php print render($page['four_third']); ?>
          <?php print render($page['four_fourth']); ?>
        </div>
      <?php endif; ?>
      <?php if ($page['footer']): print render($page['footer']); endif; ?>
    </footer>
  <?php endif; ?>

</div>

<?php if ($collapsible = render($page['collapsible'])): ?>
  <section id="section-collapsible" class="section-collapsible clearfix">
    <h2 class="collapsible-toggle"><a href="#"><?php print t('Toggle collapsible region'); ?></a></h2>
    <?php print $collapsible; ?>
  </section>
<?php endif; ?>
