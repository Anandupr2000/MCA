 <?php
$servername = "117.232.108.35";
$username = "21mca9";
$password = "21mca9";
$database = "db9";

// Create connection
$conn = new mysqli($servername, $username, $password,$database,"8000");

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

?> 
