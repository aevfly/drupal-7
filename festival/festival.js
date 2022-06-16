(function ($) {

Drupal.behaviors.festival = {
  attach: function (context){

    $('.text-format-wrapper', context).css('display', 'none');
    
    $('.form-item-sendemail input', context).click(function () {
        if (this.checked) {
          $('.text-format-wrapper', context).css('display', 'block');
        }else{
          $('.text-format-wrapper', context).css('display', 'none');
        }  
    });

    $( ".white" ).parents( "tr" ).css( "background", "#ffffff" );
    $( ".whitegray" ).parents( "tr" ).css( "background", "#dfe1e6" );
    $( ".greentext" ).parents( "tr" ).css( "background", "rgba(118, 197, 90, 0.3)" );
    $( ".bluetext" ).parents( "tr" ).css( "background", "rgba(42, 143, 195, 0.3) " );

  }
}

})(jQuery);