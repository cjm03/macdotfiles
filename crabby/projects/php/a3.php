<?php
// Task1 Helper Function
function isPrime($i) {
    if ($i < 2) return false;
    if ($i == 2) return true;
    if ($i % 2 == 0) return false;
    $square = sqrt($i);
    for ($j = 3; $j <= $square; $j += 2) {
        if ($i % $j == 0) return false;
    }
    return true;
}
$from = 5000;
$to = 5999;
// Task1 Main Function
function fiveKPrimes($from, $to) {
    for ($num = $from; $num <= $to; $num++) {
        if (isPrime($num)) {
            echo $num . "<br />";
        }
    }
}
// Task 2
class shoppingCart {
    public $items = array();

    public function addItem($item) {
        $this->items[] = $item;
        echo "'$item' added to cart<br>";
    }

    public function popItem() {
        if (!empty($this->items)) {
            $removedItem = array_pop($this->items);
            echo "removed '$removedItem' <br>";
        } else {
            echo "cart already empty<br>";
        }
    }

    public function showItems() {
        if (!empty($this->items)) {
            echo "cart:<br>";
            foreach ($this->items as $index => $item) {
                echo ($index + 1) . ". $item<br>";
            }
        } else {
            echo "cart is empty<br>";
        }
    }
}

// Task1 output
fiveKPrimes($from, $to);
echo "<br>";
// Task2 and Task3 output
$cart = new ShoppingCart();
$cart->addItem("Ball");
$cart->addItem("Watch");
$cart->addItem("Cup");
$cart->showItems();
$cart->popItem();
$cart->popItem();
$cart->popItem();
$cart->showItems();


?>
