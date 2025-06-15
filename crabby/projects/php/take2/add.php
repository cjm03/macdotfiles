<?php
require 'db.php';
require 'validation.php'; 

$errors = [];
$title = '';
$content = '';
$font_size = '14px';
$font_color = '#000000';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // collect input
    $title = trim($_POST['title'] ?? '');
    $content = trim($_POST['content'] ?? '');
    $font_size = $_POST['font_size'] ?? '14px';
    $font_color = $_POST['font_color'] ?? '#000000';

    // validate
    if (!validate_title($title)) {
        $errors['title'] = "Title must be 3 to 15 words and under 200 characters.";
    }

    if (!validate_content($content)) {
        $errors['content'] = "Content must be 20 to 200 words.";
    }

    if (!isset($_FILES['image']) || $_FILES['image']['error'] !== UPLOAD_ERR_OK) {
        $errors['image'] = "Image is required.";
    } elseif (!validate_image($_FILES['image'])) {
        $errors['image'] = "Image must be JPG or PNG and less than 2MB.";
    }

    // if valid, save image and article
    if (empty($errors)) {
        $image_name = uniqid() . '-' . basename($_FILES['image']['name']);
        $upload_path = 'uploads/' . $image_name;
        move_uploaded_file($_FILES['image']['tmp_name'], $upload_path);

        // insert into DB
        $stmt = $pdo->prepare("INSERT INTO articles (title, image, content, font_size, font_color, created_at) VALUES (?, ?, ?, ?, ?, NOW())");
        $stmt->execute([$title, $image_name, $content, $font_size, $font_color]);

        $new_id = $pdo->lastInsertId();
        header("Location: article.php?id=$new_id");
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
