<?php
// $servername = "117.232.108.35";
$servername = "localhost";
// $username = "21mca01";
$username = "21mca01";
// $password = "21mca01";
$database = "db01";
// $database = "db01";

// Create connection
$conn = new mysqli($servername, $username, $password,$database,"8000");

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

?> 