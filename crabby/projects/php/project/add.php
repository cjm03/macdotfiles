<?php
require 'db.php';
require 'validation.php'; // Import validation functions

// Initialize error messages and values
$title = $content = $font_size = '14px';
$font_color = '#000000';
$image_error = '';
$errors = [];

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Collect data from form submission
    $title = $_POST['title'];
    $content = $_POST['content'];
    $font_size = $_POST['font_size'];
    $font_color = $_POST['font_color'];

    // Initialize $image variable to prevent undefined error
    $image = $_FILES['image'] ?? null;

    // Image upload logic
    if ($image && $image['error'] === 0) {
        // Validate image before processing
        if (!validate_image($image)) {
            $errors[] = 'Invalid image. Only JPG/PNG images under 2MB are allowed.';
        } else {
            // Generate a unique filename
            $image_name = uniqid() . '-' . basename($image['name']);
            $image_path = 'uploads/' . $image_name;

            // Move the uploaded file
            if (!move_uploaded_file($image['tmp_name'], $image_path)) {
                $errors[] = 'Failed to upload image.';
            }
        }
    } elseif ($image && $image['error'] !== 0) {
        // If no image is uploaded but file input exists
        $errors[] = 'Error with the image upload. Please try again.';
    }

    // Validate other fields
    if (!validate_title($title)) {
        $errors[] = 'Title must be between 3 and 15 words, and no more than 200 characters.';
    }
    if (!validate_content($content)) {
        $errors[] = 'Content must be between 20 and 200 words.';
    }

    // If no validation errors, insert into the database
    if (empty($errors)) {
        $stmt = $pdo->prepare("INSERT INTO articles (title, image, content, font_size, font_color) 
                               VALUES (?, ?, ?, ?, ?)");
        $stmt->execute([$title, $image_name ?? null, $content, $font_size, $font_color]);

        // Redirect to the newly added article page
        header('Location: article.php?id=' . $pdo->lastInsertId());
        exit;
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Add New Article</title>
</head>
<body>
<h1>Add New Article</h1>

<form action="add.php" method="POST" enctype="multipart/form-data">
    <label>Title:<br>
        <input type="text" name="title" value="<?= htmlspecialchars($title) ?>" maxlength="200">
    </label>
    <div style="color:red;"><?= $errors['title'] ?? '' ?></div>

    <br><br>

    <label>Image:<br>
        <input type="file" name="image" accept="image/png, image/jpeg">
    </label>
    <div style="color:red;"><?= $errors['image'] ?? '' ?></div>

    <br><br>

    <label>Content:<br>
        <textarea name="content" rows="10" cols="50"><?= htmlspecialchars($content) ?></textarea>
    </label>
    <div style="color:red;"><?= $errors['content'] ?? '' ?></div>

    <br><br>

    <label>Font Size:<br>
        <select name="font_size">
            <?php foreach (['10px', '12px', '14px', '16px'] as $size): ?>
                <option value="<?= $size ?>" <?= $font_size === $size ? 'selected' : '' ?>><?= $size ?></option>
            <?php endforeach; ?>
        </select>
    </label>

    <br><br>

    <label>Font Color:<br>
        <input type="color" name="font_color" value="<?= htmlspecialchars($font_color) ?>">
    </label>

    <br><br>

    <button type="submit">Add Article</button>
</form>

</body>
</html>
