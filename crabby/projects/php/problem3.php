<?php

                                // save reference for l8r: php.net/manual/en/datetime.modify.php

$tz = "America/Indianapolis";                       // Store timezone
date_default_timezone_set($tz);                     // Set timezone
$current = new DateTime();                          // Create new DateTime object
$current->modify('+1000 days');                     // Utilize the DateTime::modify() object function's string modifier to add 1000 days
$formatted = $current->format('M d o H:i:s');       // Utilize the format function to store formatted as variable
echo $formatted;                                    // Echo the result
?>
