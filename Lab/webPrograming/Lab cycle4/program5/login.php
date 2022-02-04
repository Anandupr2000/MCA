
<?php
include "dbconnect.php";
session_start();
include "dbconnect.php";

if($conn->connect_error){
	die("connection failed");
}
$id = $_POST["id"];
$password = $_POST["password"];

$sql = mysqli_query($conn, "SELECT count(*) as total from student WHERE id = '".$id."' and password = '".$password."'");
$row = mysqli_fetch_array($sql);

if($row["total"] > 0){
        $_SESSION['id']= $id;
	header('location:welcome.php');
}

	else{
		
	?><script>
		if(window.confirm('Your id or password is error!!!! Try again'))
		{
			window.location.href='form.php';
		};</script>
	
	<?php
	}
?>