<?php

/**
 * @file
 * The taxonomy handler.
 */

/*
 * Taxonomy handler.
 */
class draggableviews_handler_taxonomy extends draggableviews_handler {
  function init($field_name, &$view) {
    parent::init($field_name, $view);
  }

  function save($tid, $value) {
    switch ($this->type) {
      case 'order':
        db_query("UPDATE {term_data} SET weight=%d WHERE tid=%d", $value, $tid);
        break;
      case 'hierarchy':
        db_query("UPDATE {term_hierarchy} SET parent=%d WHERE tid=%d", $value, $tid);
        break;
    }
  }
}
