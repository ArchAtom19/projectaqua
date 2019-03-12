//THIS SCRIPT IS OUTDATED AND CURRENTLY UNUSED. IT IS STILL REMAINS HERE AS A FALLBACK.

//This JS file handles the slideshow/carousel on the site's homepage.

var caroIndex = 1;
var carousel; //For later use.
showSlide(caroIndex);
console.log("Carousel script loaded.") //Debug log making it known that the carousel script is present and has been loaded.

function storeCarousel(){
    //Store all information about the slideshow when the page loads, ensuring that it is ready for use.
    try{
        carousel = document.getElementsByClassName("aquaIndexSlide");
    }
    catch(e){
        console.log("Error storing carousel data! The slideshow may not work properly.");
    }
}

function advance(amount){
    showSlide(caroIndex += amount);
    console.log(`Carousel advanced by ${amount}`); //Debugging.
}

function setSlide(amount){
    showSlide(caroIndex = amount);
}

function showSlide(amount){
    var i;
    
    if(amount > carousel.length){
        caroIndex = 1;
    }
    
    if(amount < 1){
        caroIndex = carousel.length;
    }
    
    for(i = 0, i < carousel.length; i++;){
        carousel[i].style.display = "none";
    }
    
    carousel[caroIndex - 1].style.display = `block`;
}