// $Id: sexybookmarks.js,v 1.2 2010/04/07 10:31:22 deciphered Exp $

(function($) {
  $(document).ready(function() {
    $('.sexybookmarks').hover(function() {
      $(this).animate(
        { height: $(this).find('.sexybookmarks-inner').height() },
        { duration: 400, queue: false}
      );
    }, function() {
      $(this).animate(
        { height: 29 },
        { duration: 400, queue: false}
      );
    })
  });
})(jQuery);
