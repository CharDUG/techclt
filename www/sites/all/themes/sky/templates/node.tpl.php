<article id="article-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $unpublished; ?>

  <?php print render($title_prefix); ?>
  <?php if(!empty($user_picture) || $title || (!empty($submitted) && $display_submitted)): ?>
    <header class="clearfix<?php $user_picture ? print ' with-picture' : ''; ?>">

      <?php print $user_picture; ?>

      <?php if ($title): ?>
        <h1<?php print $title_attributes; ?>>
          <?php if ($page): ?>
            <?php print $title; ?>
          <?php elseif (!$page): ?>
            <a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a>
          <?php endif; ?>
        </h1>
      <?php endif; ?>

      <?php if ($display_submitted): ?>
        <div class="submitted"><?php print $submitted; ?></div>
      <?php endif; ?>

    </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <div<?php print $content_attributes; ?>>
  <?php
    hide($content['comments']);
    hide($content['links']);
    print render($content);
  ?>
  </div>

  <?php if ($links = render($content['links'])): ?>
    <nav class="clearfix"><?php print $links; ?></nav>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

</article>
