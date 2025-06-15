<?php
$host = 'localhost';
$db = 'article_system';
$user = 'root';
$pass = '1234';
$charset = 'utf8mb4';

$signin = "mysql:host=$host;dbname=$db;charset=$charset";
$options = [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION, PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC, ];
try {
    $pdo = new PDO($signin, $user, $pass, $options);
} catch (\PDOException $e) {
    die("Database failed to connect" . $e->getMessage());
}
?>
