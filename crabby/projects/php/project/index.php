<?php
require 'db.php'; // Ensure the database connection is included

// Pagination setup
$per_page = 6;  // Number of articles per page
$page = isset($_GET['page']) ? (int)$_GET['page'] : 1;  // Current page
$offset = ($page - 1) * $per_page;

// Fetch the latest 6 articles with pagination
$stmt = $pdo->prepare("SELECT * FROM articles ORDER BY id DESC LIMIT :limit OFFSET :offset");
$stmt->bindParam(':limit', $per_page, PDO::PARAM_INT);
$stmt->bindParam(':offset', $offset, PDO::PARAM_INT);
$stmt->execute();
$articles = $stmt->fetchAll();

if ($articles):
    foreach ($articles as $article):
        // Display each article (adjust the HTML as needed)
        ?>
        <div class="article">
            <h2><a href="article.php?id=<?= $article['id'] ?>"><?= htmlspecialchars($article['title']) ?></a></h2>
            <img src="uploads/<?= htmlspecialchars($article['image']) ?>" alt="Article Image" width="150">
            <p><?= substr($article['content'], 0, 150) ?>...</p>
        </div>
        <?php
    endforeach;
else:
    echo 'No articles found.';
endif;

// Pagination links
$total_articles_stmt = $pdo->query("SELECT COUNT(*) FROM articles");
$total_articles = $total_articles_stmt->fetchColumn();
$total_pages = ceil($total_articles / $per_page);

if ($total_pages > 1):
    ?>
    <div class="pagination">
        <?php if ($page > 1): ?>
            <a href="?page=<?= $page - 1 ?>">Previous</a>
        <?php endif; ?>
        <?php if ($page < $total_pages): ?>
            <a href="?page=<?= $page + 1 ?>">Next</a>
        <?php endif; ?>
    </div>
    <?php
endif;
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

<!-- Pagination -->
<div>
  <?php if ($page > 1): ?>
    <a href="?page=<?= $page - 1 ?>">Previous</a>
  <?php endif; ?>
  <a href="?page=<?= $page + 1 ?>">Next</a>
</div>

</body>
</html>
