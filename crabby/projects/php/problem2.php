<?php

$items = [
    ['Apple', 1.55454],                                     // CREATE
    ['Banana', 0.8334],                                     // ARRAY
    ['Dragonfruit', 22.25333]];

echo "<pre>";                                               // begin formatted text

for ($i = 0; $i < 3; $i++) {                                // for each row in items, print the first item aligned to the right
   printf("%11s|$%8.3f.\n", $items[$i][0], $items[$i][1]);  // within 11 characters and the second item aligned to the right
}                                                           // within 8 characters following the '$' and rounded to 3 decimals

echo "</pre>";

?>
