<?php
    $username = "REDACTED FOR GITHUB REPO";
    $passHash = "F50439C24FB5241AA176BF813E44F38AA7B9B6B795E8E202B1946E21D96CB46EC481FB4A7E821AD34F782163656D497798B47D81E5AD4EA0D9ED2E5012109286";
    $connection = mysql_connect($host, $username, $password) or die("Unable to connect to MySQL server.");
    $selected = mysql_select_db("aquaauwu_aqua", $connection);
?> 