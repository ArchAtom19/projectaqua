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
                        <form action="include/unit1Display.php" method="post">
                            <table border="2" class="aquaURT" id="URT1">
                                <tr>
                                    <th>ReadingID</th>
                                    <th>DateTimeStamp</th>
                                    <th>UnitID</th>
                                    <th>Temperature</th>
                                    <th>Air Pressure</th>
                                    <th class="hovertip"><span class="aquaTTHover" id="o3TH">O&#x00B3</span>
                                        <div class="aquaUnitTooltip" name="ozoneTT">Ozone</div>
                                    </th>
                                    <th class="hovertip"><span class="aquaTTHover" id="no2TH">NO&#x00B2</span>
                                        <div class="aquaUnitTooltip" name="nitrogendioxideTT">Nitrogen Dioxide</div>
                                    </th>
                                    <th class="hovertip"><span class="aquaTTHover" id="so2TH">SO&#x00B2</span>
                                        <div class="aquaUnitTooltip" name="sulphurdioxideTT">Sulphur Dioxide</div>
                                    </th>
                                    <th class="hovertip"><span class="aquaTTHover" id="coTH">CO</span>
                                        <div class="aquaUnitTooltip" name="carbonmonoxideTT">Carbon Monoxide</div>
                                    </th>
                                    <th>PM25</th>
                                    <th>PM10</th>
                                </tr>
                                <tr>
                                    <td name="u1r1f1"></td>
                                    <td name="u1r1f2"></td>
                                    <td name="u1r1f3"></td>
                                    <td name="u1r1f4"></td>
                                    <td name="u1r1f5"></td>
                                    <td name="u1r1f6"></td>
                                    <td name="u1r1f7"></td>
                                    <td name="u1r1f8"></td>
                                    <td name="u1r1f9"></td>
                                    <td name="u1r1f10"></td>
                                    <td name="u1r1f11"></td>                                                                                         
                                </tr>
                                <tr>
                                    <td name="u1r2f1"></td>
                                    <td name="u1r2f2"></td>
                                    <td name="u1r2f3"></td>
                                    <td name="u1f2f4"></td>
                                    <td name="u1r2f5"></td>
                                    <td name="u1r2f6"></td>
                                    <td name="u1r2f7"></td>
                                    <td name="u1r2f8"></td>
                                    <td name="u1r2f9"></td>
                                    <td name="u1r2f10"></td>
                                    <td name="u1r2f11"></td>                                                                                         
                                </tr>
                                <tr>
                                    <td name="u1r3f1"></td>
                                    <td name="u1r3f2"></td>
                                    <td name="u1r3f3"></td>
                                    <td name="u1r3f4"></td>
                                    <td name="u1r3f5"></td>
                                    <td name="u1r3f6"></td>
                                    <td name="u1r3f7"></td>
                                    <td name="u1r3f8"></td>
                                    <td name="u1r3f9"></td>
                                    <td name="u1r3f10"></td>
                                    <td name="u1r3f11"></td>                                                                                         
                                </tr>
                                <tr>
                                    <td name="u1r4f1"></td>
                                    <td name="u1r4f2"></td>
                                    <td name="u1r4f3"></td>
                                    <td name="u1r4f4"></td>
                                    <td name="u1r4f5"></td>
                                    <td name="u1r4f6"></td>
                                    <td name="u1r4f7"></td>
                                    <td name="u1r4f8"></td>
                                    <td name="u1r4f9"></td>
                                    <td name="u1r4f10"></td>
                                    <td name="u1r4f11"></td>                                                                                         
                                </tr>
                                <tr>
                                    <td name="u1r5r1"></td>
                                    <td name="u1r5f2"></td>
                                    <td name="u1r5f3"></td>
                                    <td name="u1r5f4"></td>
                                    <td name="u1r5f5"></td>
                                    <td name="u1r5f6"></td>
                                    <td name="u1r5f7"></td>
                                    <td name="u1r5f8"></td>
                                    <td name="u1r5f9"></td>
                                    <td name="u1r5f10"></td>
                                    <td name="u1r5f11"></td>               
                                </tr>                               
                            </table>
                        </form>
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