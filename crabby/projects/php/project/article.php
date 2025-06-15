<?php
require 'db.php'; // your PDO connection

// Get article ID
if (!isset($_GET['id']) || !is_numeric($_GET['id'])) {
    die("Invalid article ID.");
}

$id = (int)$_GET['id'];

// Fetch the article
$statement = $pdo->prepare("SELECT * FROM articles WHERE id = ?");
$statement->execute([$id]);
$article = $statement->fetch();

if (!$article) {
    die("Article not found.");
}
?>

<!DOCTYPE html>
<html>
<head>
    <title><?= htmlspecialchars($article['title']) ?></title>
    <style>
        body {
            font-size: <?= htmlspecialchars($article['font_size']) ?>;
            color: <?= htmlspecialchars($article['font_color']) ?>;
            font-family: Arial, sans-serif;
        }
        .container {
            width: 70%;
            margin: auto;
            text-align: center;
        }
        img {
            max-width: 100%;
            height: auto;
            margin: 20px 0;
        }
        .content {
            text-align: left;
        }
    </style>
</head>
<body>
<div class="container">
    <h1><?= htmlspecialchars($article['title']) ?></h1>
    <img src="uploads/<?= htmlspecialchars($article['image']) ?>" alt="Article Image">
    <div class="content">
        <?= nl2br($article['content']) ?>
    </div>
</div>
</body>
</html>
