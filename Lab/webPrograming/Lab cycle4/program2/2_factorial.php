<!DOCTYPE html>
<html lang="en">
<head>
    <title>Factorial</title>
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
        <form action="" method="POST">
            <label for="no">Enter a number </label>
            <input type="text" name="no" id="no">
            <br>
            <button type="submit" name ="submit">Submit</button>
        </form>
    </div>
    <?php
        // if(empty($_GET[''])){};
        if(isset($_POST['submit'])){
            $num = $_REQUEST['no'];
            echo "factorial of ".$num." = ".fact($num);
        }
        function fact($num){
            #echo $num;
            if($num == 1) return 1;
            else return $num * fact($num-1);
        }
    ?>
</body>
</html>