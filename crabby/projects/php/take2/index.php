<?php
// import the database
require 'db.php'; 

// pagination logic
$perPage = 6;
$page = isset($_GET['page']) ? max(1, (int)$_GET['page']) : 1;
$offset = ($page - 1) * $perPage;

// fetch articles, create an offset and a limit to ensure bounds are not surpassed
$stmt = $pdo->prepare("SELECT * FROM articles ORDER BY created_at DESC LIMIT :offset, :limit");
$stmt->bindValue(':offset', $offset, PDO::PARAM_INT);
$stmt->bindValue(':limit', $perPage, PDO::PARAM_INT);
$stmt->execute();
$articles = $stmt->fetchAll();
?>

<!DOCTYPE html>
<html>
<head>
  <title>Home - Articles</title>
  <style>
    .container { display: flex; gap: 20px; }
    .column { flex: 1; }
    .article { border: 1px solid #ccc; padding: 10px; margin-bottom: 15px; }
    img { max-width: 100%; height: auto; }
  </style>
</head>
<body>

<h1>Latest Articles</h1>
<div class="container">
  <div class="column">
    <!-- display each article --->
    <?php for ($i = 0; $i < 3 && $i < count($articles); $i++): ?>
      <div class="article">
        <h2><?= htmlspecialchars($articles[$i]['title']) ?></h2>
        <img src="uploads/<?= htmlspecialchars($articles[$i]['image']) ?>" alt="Article Image">
        <p>
          <?= implode(' ', array_slice(explode(' ', strip_tags($articles[$i]['content'])), 0, 50)) ?>...
        </p>
        <a href="article.php?id=<?= $articles[$i]['id'] ?>">Read More</a>
      </div>
    <?php endfor; ?>
  </div>
  <div class="column">
    <?php for ($i = 3; $i < 6 && $i < count($articles); $i++): ?>
      <div class="article">
        <h2><?= htmlspecialchars($articles[$i]['title']) ?></h2>
        <img src="uploads/<?= htmlspecialchars($articles[$i]['image']) ?>" alt="Article Image">
        <p>
          <?= implode(' ', array_slice(explode(' ', strip_tags($articles[$i]['content'])), 0, 50)) ?>...
        </p>
        <a href="article.php?id=<?= $articles[$i]['id'] ?>">Read More</a>
      </div>
    <?php endfor; ?>
  </div>
</div>

<!-- pagination -->
<div>
  <?php if ($page > 1): ?>
    <a href="?page=<?= $page - 1 ?>">Previous</a>
  <?php endif; ?>
  <a href="?page=<?= $page + 1 ?>">Next</a>
</div>

</body>
</html>
