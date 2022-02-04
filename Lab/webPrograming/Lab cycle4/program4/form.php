<html>
    <head>
        <link rel="stylesheet" href="form.css">
    </head>
<body>


<!-- Use a table here!! -->
<?php
//include "dbconnect.php";
?>

<div><br><h1>&nbsp;&nbsp;Enter Book-Details</h1><br>
<form action="insert.php" method="post">
 <input type="text" name="title" placeholder="Enter book title" required><br><br>
<input type="int" name="bookno" placeholder="Enter book number"required><br><br>
<input type="text" name="publisher" placeholder="Enter book publisher"required><br><br>
<input type="text" name="edition" placeholder="Enter book edition"required><br><br><br>
<input type="submit" value="ADD">
</form>
<br>
<button><a href="view.php">VIEW BOOKS</a></button>


</div>
</body>
</html>

