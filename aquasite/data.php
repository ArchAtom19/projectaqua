<!DOCTYPE html>
<html>
    
    <head>
        <meta charset="utf-8">
        <title>PROJECT AQUA</title>
        <meta name="description" content="Welcome to PROJECT AQUA.">
        <link rel="stylesheet" href="css/main.css">
        <script src="js/unitControl.js"></script>
    </head>
    
    <?php include("include/logoHeader.php"); ?>
    
    <body>
        <div id="mainArea">
            <section>
                <h1 class="aquaPageTitle">Our Latest Readings</h1>
                <p>This page shows the latest readings that have been recorded by each of our units.</p>
            </section>
            
            <section id="aquaUnitReadings">
                <div class="aquaUnitReadingBox">
                    <div class="aquaUnitReadingBoxHeader">
                        <span class="aquaReadingsTextHeader">UNIT 1</span>
                        <img class="ARTB" id="toggleButton1" src="img/aquaButtonExpand.png" onclick="unitToggle(1)"/>
                    </div>
                    <div class="aquaUnitResultsTableDiv" id="aquaUnitResults1">

                    </div>
                </div>
                <div class="aquaUnitReadingBox">
                    <div class="aquaUnitReadingBoxHeader">
                        <span class="aquaReadingsTextHeader">UNIT 2</span>
                        <img class="ARTB" id="toggleButton2" src="img/aquaButtonExpand.png" onclick="unitToggle(2)"/>
                    </div>
                    <div class="aquaUnitResultsTableDiv" id="aquaUnitResults2">

                    </div>                    
                </div>
                <div class="aquaUnitReadingBox">
                    <div class="aquaUnitReadingBoxHeader">
                        <span class="aquaReadingsTextHeader">UNIT 3</span>
                        <img class="ARTB" id="toggleButton3" src="img/aquaButtonExpand.png" onclick="unitToggle(3)"/>
                    </div>
                    <div class="aquaUnitResultsTableDiv" id="aquaUnitResults3">
                        
                    </div>
                </div>
                <div class="aquaUnitReadingBox">
                    <div class="aquaUnitReadingBoxHeader">
                        <span class="aquaReadingsTextHeader">UNIT 4</span>
                        <img class="ARTB" id="toggleButton4" src="img/aquaButtonExpand.png" onclick="unitToggle(4)"/>
                    </div>
                    <div class="aquaUnitResultsTableDiv" id="aquaUnitResults4">

                    </div>
                </div>
                <div class="aquaUnitReadingBox">
                    <div class="aquaUnitReadingBoxHeader">
                        <span class="aquaReadingsTextHeader">UNIT 5</span>
                        <img class="ARTB" id="toggleButton5" src="img/aquaButtonExpand.png" onclick="unitToggle(5)"/>
                    </div>
                    <div class="aquaUnitResultsTableDiv" id="aquaUnitResults5">
                        <p>TEST</p><br />
                        <p>TEST</p><br />
                        <p>TEST</p><br />
                        <p>TEST</p><br />
                        <p>TEST</p><br />
                        <p>TEST</p><br />
                        <p>TEST</p><br />
                        <p>TEST</p><br />
                        <p>TEST</p><br />
                        <p>TEST</p><br />
                        <p>TEST</p><br />
                    </div>
                </div>
            </section>
        </div>
    </body>
    
    <?php include("include/pageFooter.php"); ?>
</html>