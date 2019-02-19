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
                        <img class="ARTB" id="toggleButton1" src="img/aquaButtonExpand.png" alt="Expand" onclick="unitToggle(1)"/>
                    </div>
                    <div class="aquaUnitResultsTableDiv" name="rBox" id="aquaUnitResults1">

                    </div>
                </div>
                <div class="aquaUnitReadingBox">
                    <div class="aquaUnitReadingBoxHeader">
                        <span class="aquaReadingsTextHeader">UNIT 2</span>
                        <img class="ARTB" id="toggleButton2" src="img/aquaButtonExpand.png" alt="Expand" onclick="unitToggle(2)"/>
                    </div>
                    <div class="aquaUnitResultsTableDiv" name="rBox" id="aquaUnitResults2">

                    </div>                    
                </div>
                <div class="aquaUnitReadingBox">
                    <div class="aquaUnitReadingBoxHeader">
                        <span class="aquaReadingsTextHeader">UNIT 3</span>
                        <img class="ARTB" id="toggleButton3" src="img/aquaButtonExpand.png" alt="Expand" onclick="unitToggle(3)"/>
                    </div>
                    <div class="aquaUnitResultsTableDiv" name="rBox" id="aquaUnitResults3">
                        
                    </div>
                </div>
                <div class="aquaUnitReadingBox">
                    <div class="aquaUnitReadingBoxHeader">
                        <span class="aquaReadingsTextHeader">UNIT 4</span>
                        <img class="ARTB" id="toggleButton4" src="img/aquaButtonExpand.png" alt="Expand" onclick="unitToggle(4)"/>
                    </div>
                    <div class="aquaUnitResultsTableDiv" name="rBox" id="aquaUnitResults4">

                    </div>
                </div>
                <div class="aquaUnitReadingBox">
                    <div class="aquaUnitReadingBoxHeader">
                        <span class="aquaReadingsTextHeader">UNIT 5</span>
                        <img class="ARTB" id="toggleButton5" src="img/aquaButtonExpand.png" alt="Expand" onclick="unitToggle(5)"/>
                    </div>
                    <div class="aquaUnitResultsTableDiv" name="rBox" id="aquaUnitResults5">
                        <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus ante arcu, consectetur vel iaculis vel, mattis tempus arcu. Sed sed nibh sit amet erat sodales gravida. Ut aliquam mattis tincidunt. Aenean dignissim dolor mi. Nulla faucibus dolor a dolor posuere volutpat. Phasellus egestas nisl at molestie auctor. Donec imperdiet metus lobortis varius pellentesque. Quisque finibus erat vel ipsum rutrum viverra at a risus. Vivamus sagittis mi laoreet, sodales leo sit amet, tristique metus. Donec at ligula non ex sagittis malesuada. Vivamus magna enim, pretium sed consequat ut, accumsan sit amet magna. Praesent imperdiet orci at varius pellentesque. Sed varius vestibulum nulla, vitae tincidunt enim dignissim in. Vivamus accumsan erat enim, pulvinar finibus arcu convallis quis. Nulla finibus imperdiet nulla, at vulputate risus varius in. Suspendisse vestibulum mollis ex, quis mattis mauris pretium vehicula.</p>
                        <p>Sed luctus arcu accumsan, varius odio sed, aliquet lacus. Etiam et risus velit. Phasellus magna odio, finibus et ante vitae, condimentum vehicula velit. Maecenas dignissim mauris ac molestie scelerisque. Cras et libero at erat accumsan porttitor id quis mauris. Nam vehicula mi sit amet ipsum euismod, sed auctor ligula viverra. Sed vel eros turpis.</p>
                        <p>Curabitur vulputate sapien eu purus efficitur, id pellentesque nunc scelerisque. Morbi accumsan sem id diam elementum posuere. Donec elementum vulputate lacus. Suspendisse vehicula semper libero, quis hendrerit arcu ultrices a. Quisque semper, ipsum nec imperdiet tristique, orci lacus ullamcorper mauris, et venenatis sapien nisi quis ante. Phasellus at magna turpis. Nunc sagittis sollicitudin auctor. Pellentesque scelerisque faucibus dignissim. Ut faucibus aliquam imperdiet. Praesent risus velit, suscipit vitae hendrerit eu, volutpat vel lorem. Vestibulum vitae ipsum nulla. </p>
                        <p>Phasellus odio nulla, rutrum et dictum et, pretium ac tortor. Ut id lobortis nibh. Aliquam diam ante, faucibus in fringilla sed, viverra in metus. Nulla imperdiet tempor efficitur. Sed eget ullamcorper ex, nec pharetra nunc. Ut fermentum faucibus neque quis tempus. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Etiam eros risus, sagittis vel elementum interdum, ullamcorper in nisi. </p>
                        <p>Maecenas ac aliquam ipsum. Vivamus sed nibh ultrices, aliquam felis sagittis, congue urna. Morbi quis bibendum mauris, scelerisque mattis nibh. Aenean molestie lobortis pretium. Sed sed risus in mauris volutpat hendrerit. In tincidunt risus ut mauris vehicula, quis commodo dui dignissim. In ultricies sodales purus, vel semper nulla aliquam placerat. Mauris egestas enim quam, non lobortis dolor mollis lacinia. Mauris tempus eleifend nisl vitae dictum. Praesent euismod in purus sit amet finibus. Aliquam erat volutpat. </p>
                    </div>
                </div>
            </section>
        </div>
        
        <?php include("include/pageFooter.php"); ?>
        
    </body>
    
    
</html>