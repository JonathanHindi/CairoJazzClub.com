// $Id: sexybookmarks.admin.js,v 1.1 2010/02/12 07:06:32 deciphered Exp $

(function($) {
  $(document).ready(function() {
    $('#sexybookmarks').sortable({
      items:  '.form-item',
      delay:   250,
      cursor:  'move',
      scroll:  true,
      revert:  true, 
      opacity: 0.7,
      stop:  function(event, ui) {
        $('#edit-sort').val($('#sexybookmarks').sortable('toArray'));
      }
    });

    // Select all icons upon clicking.
    $('#sel-all').click(function() {
      $('#sexybookmarks INPUT').attr('checked', 'checked');
    });

    // Deselect all icons upon clicking.
    $('#sel-none').click(function() {
      $('#sexybookmarks INPUT').removeAttr('checked');
    });

    // Select most popular icons upon clicking.
    $('#sel-pop').click(function() {
      var popular = [
        'digg', 'reddit', 'delicious', 'stumbleupon', 'mixx', 'twitter',
        'technorati', 'misterwong', 'diigo'
      ];
      $('#sexybookmarks INPUT').removeAttr('checked');
      $.each(popular, function(i) {
        $('#edit-bookmarks-' + popular[i]).attr('checked', 'checked');
      });
    });
  });
})(jQuery);