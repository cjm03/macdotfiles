<?php
require 'db.php';
require 'validation.php';

if (!isset($_GET['id']) || !is_numeric($_GET['id'])) {
    die("Invalid article ID.");
}
$id = (int)$_GET['id'];

// Fetch existing article
$statement = $pdo->prepare("SELECT * FROM articles WHERE id = ?");
$statement->execute([$id]);
$article = $statement->fetch();

if (!$article) {
    die("Article not found.");
}

// Initialize variables with existing values
$title = $article['title'];
$content = $article['content'];
$font_size = $article['font_size'];
$font_color = $article['font_color'];
$old_image = $article['image'];
$errors = [];

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $title = trim($_POST['title'] ?? '');
    $content = trim($_POST['content'] ?? '');
    $font_size = $_POST['font_size'] ?? '14px';
    $font_color = $_POST['font_color'] ?? '#000000';

    // Validate
    if (!validate_title($title)) {
        $errors['title'] = "Title must be 3 to 15 words and under 200 characters.";
    }

    if (!validate_content($content)) {
        $errors['content'] = "Content must be 20 to 200 words.";
    }

    $image_name = $old_image;

    // Handle optional image upload
    if (isset($_FILES['image']) && $_FILES['image']['error'] === UPLOAD_ERR_OK) {
        if (!validate_image($_FILES['image'])) {
            $errors['image'] = "Image must be JPG or PNG and less than 2MB.";
        } else {
            // Save new image and delete old one
            $image_name = uniqid() . '-' . basename($_FILES['image']['name']);
            $upload_path = 'uploads/' . $image_name;
            move_uploaded_file($_FILES['image']['tmp_name'], $upload_path);

            // Delete old image file
            if ($old_image && file_exists("uploads/$old_image")) {
                unlink("uploads/$old_image");
            }
        }
    }

    // Update article in DB
    if (empty($errors)) {
        $statement = $pdo->prepare("UPDATE articles SET title = ?, image = ?, content = ?, font_size = ?, font_color = ? WHERE id = ?");
        $statement->execute([$title, $image_name, $content, $font_size, $font_color, $id]);

        header("Location: article.php?id=$id");
        exit;
    }
}
?>


<!DOCTYPE html>
<html>
<head>
    <title>Edit Article</title>
</head>
<body>
<h1>Edit Article</h1>

<form action="edit.php?id=<?= $id ?>" method="POST" enctype="multipart/form-data">
    <label>Title:<br>
        <input type="text" name="title" value="<?= htmlspecialchars($title) ?>" maxlength="200">
    </label>
    <div style="color:red;"><?= $errors['title'] ?? '' ?></div>

    <br><br>

    <label>Current Image:<br>
        <img src="uploads/<?= htmlspecialchars($old_image) ?>" width="200"><br>
        Replace image: <input type="file" name="image" accept="image/png, image/jpeg">
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

    <button type="submit">Update Article</button>
</form>

</body>
</html>
