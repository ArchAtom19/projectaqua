<?php 
$link = mysqli_connect("localhost", "aquaauwu_Admin", "A[5l_)@_40!r!SI.","aquaauwu_aqua");
    
if (isset($_GET['id']) && isset($_GET['temp']) && isset($_GET['press']) &&
        isset($_GET['o3']) && isset($_GET['no2']) && isset($_GET['so2']) && 
        isset($_GET['co']) && isset($_GET['pm25']) && isset($_GET['pm10'])) {

        $stmt = mysqli_prepare($link, "INSERT INTO sensorreadings (SensorID, Temperature, AirPressure, ReadingO3, ReadingNO2, ReadingSO2, ReadingCO, ReadingPM25, ReadingPM10) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");

        mysqli_stmt_bind_param($stmt,'idddddddd', $id, $temp, $press, $o3, $no2, $so2, $co, $pm25, $pm10);

        $id = $_GET['id'];
        $temp = $_GET['temp'];
        $press = $_GET['press']; 
        $o3 = $_GET['o3'];
        $no2 = $_GET['no2'];
        $so2 = $_GET['so2'];
        $co = $_GET['co'];
        $pm25 = $_GET['pm25'];
        $pm10 = $_GET['pm10'];
                
        if (!mysqli_stmt_execute($stmt)) {
            printf("Errormessage: %s\n", mysqli_error($link));
            exit();
        }

        printf("%d Row inserted.\n", mysqli_stmt_affected_rows($stmt));
    } else {
        echo "Not A Valid Record";
    }
?>  