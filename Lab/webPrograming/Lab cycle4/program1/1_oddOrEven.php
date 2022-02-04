<!DOCTYPE html>
<html lang="en">
<head>
    <title>Odd or Even</title>
    <style>
        div{
            padding-left: 200px;
        }
        input{
            margin: 20px 20px 20px 50px;
        }
    </style>
</head>
<body>
    <div>
        <form action="" method="get">
            <label for="no">Enter a number </label>
            <input type="text" name="no" id="no">
            <br>
            <button type="submit" name ="submit">Submit</button>
        </form>
    </div>
    <?php
        // if(empty($_GET[''])){};
        if(isset($_GET['submit'])){
            $num = $_REQUEST['no'];
            if($num%2==0) echo "Entered number is even";
            else echo "Entered number is odd";
        }
    ?>
</body>
</html>