<?php
function concStr($str1, $str2): string {
    // concStr: Pass two strings and return them after concatenating
    return $str1 . $str2;
}
function sumDiag($array): int {
    // sumDiag: Pass a 3x3 array and the diagonals will be summed
    // calculation will be the sum of elements 1, 5, 9, 3, and 7
    $tlTobr = $array[0][0] + $array[1][1] + $array[2][2];
    $trTobl = $array[0][2] + $array[1][1] + $array[2][0];
    return $tlTobr + $trTobl;
}
// Print the result of concatening strings 'Charles' and 'Moye'
echo concStr('Charles', 'Moye');
// Newline for readability
echo "<br>";
// Print the result of summing the diagonals from the provided array
echo sumDiag(array(array(1, 2, 3), array(4, 5, 6), array(7, 8, 9)));
?>
