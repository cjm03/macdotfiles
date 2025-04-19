<?php
function get2dArray($intRows, $intCols) {

    // Initialize the array to be returned as empty
    
    $returnArr = [];

    // Add a new array to returnArr until it has reached the
    // specified amount of rows
    
    for ($i = 0; $i < $intRows; $i++) {

        // Initialize array for each row
        
        $row = [];

        // Create random integers for the specified amount of
        // columns and add them to the current row array
        
        for ($j = 0; $j < $intCols; $j++) {
            $row[$j] = random_int(1, 100);
        }

        // Add the newly created and populated row array to 
        // the main 2d array
        
        $returnArr[$i] = $row;
    }

    // Return the array
    
    return $returnArr;
}

function printArray($array2d) {

    // begin table
    
    $table = '<table border="1">';

    // iterate through each row in the array
    
    foreach ($array2d as $row) {

        $table .= '<tr>';                       // add a table row

        foreach ($row as $col) {                // add each columns value to the row
            $table .= '<td>' . $col . '</td>';
        }
        $table .= '</tr>';                      // close the table row and repeat until all rows accounted for
    }

    $table .= '</table>';                       // close the table
    return $table;
}
// qol function to add 5 to numbers when using array_map()
function addF($n) {

    return ($n + 5);

}

$rows = 5;
$cols = 8;
$arr = get2dArray($rows, $cols);                // call get2dArray to get an array with 5 rows and 8 columns

echo printArray($arr);                          // print its content
echo "<br />";
echo "<br />";

for ($i = 0; $i < $rows; $i++) {                // iterate through each row and add 5 to each row element

    $arr[$i] = array_map('addF', $arr[$i]);

}

echo printArray($arr);                          // print the updated array's content



?>
