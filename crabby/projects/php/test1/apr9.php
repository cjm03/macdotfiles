<?php
$tz = "America/Indianapolis";
date_default_timezone_set($tz);
$minutes = date("i");
$minutes += (30);
$hours = date("g");
if ($minutes >= 60) {
    $minutes -= 60;
    $hours += 1;
}
echo date("o-m-j $hours:$minutes:s");

?>
