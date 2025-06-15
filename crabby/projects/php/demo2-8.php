<?php
// builtin error types:
    // E_ERROR (fatal errors)
    // E_WARNING
    // E_NOTICE
    // E_PARSE
    // E_ALL
error_reporting(E_ALL);

// try-catch
try {
    throw new Exception("Something went wrong");
} catch (Exception $e) {
    echo "Caught exception: " . $e->getMessage();
}
// regex
    // preg_match()
    // preg_replace()
    // preg_match_all()
// regex symbols
        // .    :   Any char except newline
        // ^    :   
        // $    :   
        // \d   :   
        // \w   :   
        // \s   :   
        // +    :   
        // *    :   
        // []   :   C
// define a pattern
$pattern = "/abc/";
$string = "abcdef";
if (preg_match($pattern, $string)) {
    echo "Pattern matches!";
} else {
    echo "Pattern not matched!";
}
$string2 = "Price: $100";
echo preg_replace("/\\$\d/", "##", $string2);


?>
