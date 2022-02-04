<?php
error_reporting(E_ERROR | E_PARSE);
include("dbconnect.php");
$sql = "SELECT * FROM book";
$result = $conn->query($sql);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
        <link rel="stylesheet" href="form.css">
    
</head>
<body><p align="right"><button id="kk"><a href="form.php">BACK</a></button></p><center><br><br>
<br>    <div id="bb"> 
        <table>
            <tr>
            <th>BOOK NO.</th>
            <th>BOOK TITLE</th>
            <th>BOOK EDITION</th>
            <th>BOOK PUBLISHER</th>
            </tr>

								<?php
			if ($result->num_rows > 0) {
				//output data of each row
				while ($row = $result->fetch_assoc()) {
		?>


            <tr>
           <b>     <td><?php echo $row['bookno']; ?></td>
                <td><?php echo $row['title']; ?></td>
                <td><?php echo $row['edition']; ?></td>
                <td><?php echo $row['publisher']; ?></td><b>
</tr>
<?php		}
			}
		?>

</table>
</div>
</body>
</html>