<?php
include "dbconnect.php";

$bookno=$_POST["bookno"];
$title=$_POST["title"];
$publisher=$_POST["publisher"];
$edition=$_POST["edition"];

$sql = "INSERT INTO book VALUES('$bookno','$title','$publisher','$edition');";


if($conn->query($sql) === TRUE){
	?>
	<script>
		if(window.confirm('Book data added succsesfully'))
		{
			window.location.href='form.php';
		};</script>
	<?php
}
else{
	?>
	<script>
		if(window.confirm('Oops!!!!!   failed '))
		{
			window.location.href='form.php';
		};</script>
	<?php
}

?> 
