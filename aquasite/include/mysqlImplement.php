<?php
    $configFile = include(dirname(__DIR__, 1) . "/credentials/config.php"); //Config file.
    $username = $configFile["username"];
    $password = $configFile["password"];
    $connection = mysqli_connect("server125.web-hosting.com:2083", $username, $password, "aquaauwu_aqua") or die("Unable to connect to MySQL server.");
    $selected = mysql_select_db("aquaauwu_aqua", $connection);

    if(!$connection){
        die("FAILED TO CONNECT TO MYSQL SERVER: " . mysql_connect_error());
    }
    
    //SQL statements for getting readings from each statement. Limit to top 5.
    $sqlSensor1 = "SELECT * FROM sensorreadings WHERE SensorID = 1 ORDER BY ReadingID DESC LIMIT 5";
    $sqlSensor2 = "SELECT * FROM sensorreadings WHERE SensorID = 2 ORDER BY ReadingID DESC LIMIT 5";
    $sqlSensor3 = "SELECT * FROM sensorreadings WHERE SensorID = 3 ORDER BY ReadingID DESC LIMIT 5";    
    $sqlSensor4 = "SELECT * FROM sensorreadings WHERE SensorID = 4 ORDER BY ReadingID DESC LIMIT 5";
    $sqlSensor5 = "SELECT * FROM sensorreadings WHERE SensorID = 5 ORDER BY ReadingID DESC LIMIT 5";
    
    //Queries for each sensor.
    $querySensor1 = mysqli_query($connection, $sqlSensor1);
    $querySensor2 = mysqli_query($connection, $sqlSensor2);
    $querySensor3 = mysqli_query($connection, $sqlSensor3);
    $querySensor4 = mysqli_query($connection, $sqlSensor4);
    $querySensor5 = mysqli_query($connection, $sqlSensor5);
?> 