/* This is the current version of the carousel script.
 * This script is used for contolling the slideshow on index.php.
 * For the original version of this script, see carousel_old.js
 */

var slideIndex = 1;
showSlides(slideIndex);

// Next/previous controls
function advance(n) {
  showSlides(slideIndex += n);
}

// Thumbnail image controls
function currentSlide(n) {
  showSlides(slideIndex = n);
}

function showSlides(n) {
  var i;
  var slides = document.getElementsByClassName("aquaIndexSlide");
  var dots = document.getElementsByClassName("aquaSlidePick");
  if (n > slides.length) {slideIndex = 1} 
  if (n < 1) {slideIndex = slides.length}
  for (i = 0; i < slides.length; i++) {
      slides[i].style.display = "none"; 
  }
  for (i = 0; i < dots.length; i++) {
      dots[i].className = dots[i].className.replace(" active", "");
  }
  slides[slideIndex-1].style.display = "block"; 
  dots[slideIndex-1].className += " active";
}

function confirmInfo(){
    //This is a debug function that will not be used at all in the finished product.
    console.log(`CLASS NAMES FOUND:\n${caro}\n\nCHOOSERS FOUND:\n${chooser}`)
}