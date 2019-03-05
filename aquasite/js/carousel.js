//This JS file handles the slideshow/carousel on the site's homepage.

var caroIndex = 1;
showSlide(caroIndex);

function advance(amount){
    showSlide(caroIndex += amount);
}

function setSlide(amount){
    showSlide(caroIndex = amount)
}

function showSlide(amount){
    var i;
    var carousel = document.getElementsByClassName("aquaIndexSlide");
    
    if(amount > carousel.length){
        caroIndex = 1;
    }
    
    if(amount < 1){
        caroIndex = carousel.length;
    }
    
    for(i = 0, i < carousel.length; i++){
        carousel[i].style.display = "none";
    }
    
    carousel[caroIndex - 1].style.display = `block`;
}