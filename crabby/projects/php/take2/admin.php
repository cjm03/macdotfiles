<?php
require 'db.php';

if (isset($_GET['delete']) && is_numeric($_GET['delete'])) {
    $id = (int)$_GET['delete'];

    // fetch article to get image filename
    $stmt = $pdo->prepare("SELECT image FROM articles WHERE id = ?");
    $stmt->execute([$id]);
    $article = $stmt->fetch();

    if ($article) {
        // delete image file
        $image_path = "uploads/" . $article['image'];
        if (file_exists($image_path)) {
            unlink($image_path);
        }

        // delete article
        $stmt = $pdo->prepare("DELETE FROM articles WHERE id = ?");
        $stmt->execute([$id]);
    }

    // redirect to avoid repeat deletion on refresh
    header("Location: admin.php");
    exit;
}

// get all articles
$stmt = $pdo->query("SELECT id, title FROM articles ORDER BY id DESC");
$articles = $stmt->fetchAll();
?>


<!DOCTYPE html>
<html>
<head>
    <title>Admin Dashboard</title>
    <style>
        table { width: 100%; border-collapse: collapse; }
        th, td { border: 1px solid #ccc; padding: 10px; text-align: left; }
        .actions a { margin-right: 10px; }
    </style>
</head>
<body>

<h1>Admin Dashboard</h1>

<a href="add.php">+ Add New Article</a>

<table>
    <thead>
        <tr>
            <th>Title</th>
            <th>Actions</th>
        </tr>
    </thead>
    <tbody>
        <?php foreach ($articles as $article): ?>
            <tr>
                <td><?= htmlspecialchars($article['title']) ?></td>
                <td class="actions">
                    <a href="edit.php?id=<?= $article['id'] ?>">Edit</a>
                    <a href="admin.php?delete=<?= $article['id'] ?>" onclick="return confirm('Delete this article?')">Delete</a>
                </td>
            </tr>
        <?php endforeach; ?>
    </tbody>
</table>

</body>
</html>
