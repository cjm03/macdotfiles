<?php
// ensure title fits parameters
function validate_title(string $title): bool {
    $word_count = str_word_count($title);
    return $word_count >= 3 && $word_count <= 15 && strlen($title) <= 200;
}
// ensure content of article fits parameters
function validate_content(string $content): bool {
    $word_count = str_word_count($content);
    return $word_count >= 20 && $word_count <= 200;
}
// ensure the image is what we want it to be
function validate_image(array $image): bool {
    // check file size
    if ($image['size'] > 2 * 1024 * 1024) {
        return false;
    }

    // check file extension/type
    $valid_types = ['image/jpeg', 'image/png'];
    $mime_type = mime_content_type($image['tmp_name']);
    return in_array($mime_type, $valid_types);
}
?>
