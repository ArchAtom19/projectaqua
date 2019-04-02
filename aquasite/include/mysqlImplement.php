<?php
    $configFile = include("../credentials/config.php"); //Config file.
    $username = ;
    $passHash = ;
    $connection = mysql_connect($host, $username, $password) or die("Unable to connect to MySQL server.");
    $selected = mysql_select_db("aquaauwu_aqua", $connection);
?> 