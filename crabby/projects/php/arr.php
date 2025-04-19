<!doctype html>
<html lang="en-US">
    <head>
        <title>arr.php</title>
    </head>
<body>
    <?php
    $ng = array('John' => "85",
        'Mary' => 92,
        'Paul' => 76,
        'Lucy' => 88,
        'David' => 95);
    echo "<br>";
    $isarr = is_array($ng);
    echo "$isarr";
    echo "<br>";
    $keys = array_keys($ng);
    print_r($keys);
    echo "<br>";
    // foreach example
    foreach ($ng as $name => $grade)
        if ($grade > 90)
            echo "$name: $grade<br>";
        //echo "$name: $grade<br>";

    ?>
</body>
</html>
