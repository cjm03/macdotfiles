<?php
function validate_title($title) {
    $wc = str_word_count($title);
    return $wc >= 3 && $wc <= 15 && strlen($title) <= 200;
}

function validate_content($content) {
    $wc = str_word_count($content);
    return $wc >= 20 && $wc <= 200;
}

function validate_image($image)
{
    // Check if image is not null and is an array
    if (!$image || !is_array($image)) {
        return false;
    }

    $allowed_types = ['image/jpeg', 'image/png'];
    $max_size = 2 * 1024 * 1024; // 2MB

    // Check MIME type and size
    $mime_type = mime_content_type($image['tmp_name']);
    if (!in_array($mime_type, $allowed_types)) {
        return false;
    }

    if ($image['size'] > $max_size) {
        return false;
    }

    return true;
}
?>
