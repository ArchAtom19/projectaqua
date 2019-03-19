<!DOCTYPE html>
<html>
    
    <head>
        <meta charset="utf-8">
        <title>PROJECT AQUA</title>
        <meta name="description" content="Welcome to PROJECT AQUA.">
        <link rel="stylesheet" href="css/main.css">
        <script src="http://code.jquery.com/jquery-3.3.1.js" integrity="sha256-2Kok7MbOyxpgUVvAk/HJ2jigOSYS2auK4Pfzbm7uH60=" crossorigin="anonymous"></script>
        <script src="js/carousel.js"></script>
        <script src="js/indexConfirmAccessDebug.js"></script>
    </head>
    
    <?php include("include/logoHeader.php"); ?>
    
    <body>
        <div id="debugZone" onload="setAccess()">
            <button id="debugButton" onclick="confirmInfo()">CONFIRM INFO</button>
        </div>
        <div id="mainArea">
            <div id="aquaSlideContainer">
                
                <div class="aquaIndexSlide" id="firstSlide">
                    <img class="aquaSlideImage" src="img/aquaUnitCollege2_crop.jpg" />
                    <div class="aquaIndexSlideCaptionWrapper">
                        <div class="aquaIndexSlideCaption" id="captionCircle1">
                            Discover how Project AQUA is helping your community.
                            
                            <a href="aboutus.php"><div class="aquaCaroCapButton"><span>Find Out More</span></div></a>
                        </div>
                    </div>
                </div>
                
                <div class="aquaIndexSlide">
                    <img class="aquaSlideImage" src="img/aquaUnitCollege2_crop.jpg" />
                    <div class="aquaIndexSlideCaptionWrapper">
                        <div class="aquaIndexSlideCaption" id="captionCircle1">
                            Slide 2
                            
                            <a href="aboutus.php"><div class="aquaCaroCapButton"><span>Find Out More</span></div></a>
                        </div>
                    </div>
                </div>
                
                <div class="aquaIndexSlide">
                    <img class="aquaSlideImage" src="img/aquaUnitCollege2_crop.jpg" />
                    <div class="aquaIndexSlideCaptionWrapper">
                        <div class="aquaIndexSlideCaption" id="captionCircle1">
                            Slide 3
                            
                            <a href="aboutus.php"><div class="aquaCaroCapButton"><span>Find Out More</span></div></a>
                        </div>
                    </div>
                </div>
                
                <div class="aquaIndexSlide">
                    <img class="aquaSlideImage" src="img/aquaUnitCollege2_crop.jpg" />
                    <div class="aquaIndexSlideCaptionWrapper">
                        <div class="aquaIndexSlideCaption" id="captionCircle1">
                            Slide 4
                            
                            <a href="aboutus.php"><div class="aquaCaroCapButton"><span>Find Out More</span></div></a>
                        </div>
                    </div>
                </div>
                
                <div class="aquaCaroAdvance" id="advancePrevious" onclick="advance(-1)"><span class="caroAdvSymbol">&#x00AB;</span></div>
                <div class="aquaCaroAdvance" id="advanceNext" onclick="advance(1)"><span class="caroAdvSymbol">&#x00BB;</span></div>
                            
            </div>
            <div id="aquaCarouselDotsContainer">
                    
                <div class="aquaSlidePick" id="pick1"></div>
                <div class="aquaSlidePick" id="pick2"></div>
                <div class="aquaSlidePick" id="pick3"></div>
                <div class="aquaSlidePick" id="pick4"></div>
                    
             </div>

            <?php include("include/pageFooter.php"); ?>
        </div>
    </body>
</html>