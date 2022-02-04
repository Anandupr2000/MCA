<!DOCTYPE html>
<html lang="en">
<head>
    <title>Odd or Even</title>
    <style>
        div{
            margin-left: 200px;
            margin-top: 50px;
        }
        input{
            margin: 20px 20px 30px 60px;
        }
        textarea{
            margin: 20px 20px 30px 60px;
            padding: 10px;
        }
    </style>
</head>
<body>
    <div>
        <h1>Student Registration</h1>
        <form action="" method="get">
            <label for="nameInp">Name </label>
            <input type="text" name="name" id="nameInp">
            <br>
            <label for="classInp">Class </label>
            <input type="text" name="class" id="classInp">
            <br>
            <label for="emailInp">Email id </label>
            <input type="email" name="email" id="emailInp">
            <br>
            <label for="addressInp">Address </label> <br>
            <textarea rows="5" cols="30" name="address" id="addressInp"></textarea>
            <br>
            <label for="genderInp">Gender </label>
            <input type="checkbox" value="male" name="gender" id="genderInp">Male
            <input type="checkbox" value="female" name="gender" id="genderInp">Female
            <br>
            <label for="dobInp">Date of Birth </label>
            <input type="date" name="dob" id="dobInp">
            <br>
            <button type="submit" name ="submit">Submit</button>
        </form>
    </div>
    <?php
        // if(empty($_GET[''])){};
        if(isset($_GET['submit'])){
            echo "<br>Name - ".$_REQUEST['name'];
            echo "<br>Email - ".$_REQUEST['email'];
            echo "<br>Address - ".$_REQUEST['address'];
            echo "<br>Gender - ".$_REQUEST['gender'];
            echo "<br>Date of birth - ".$_REQUEST['dob'];
        }
    ?>
</body>
</html>