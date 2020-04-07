<?php

  //Connecting to mySQL
  $servername = "mysql.eecs.ku.edu";
  $username = "agrowney";
  $password = 'P@$$word123';

  $conn = new mysqli($servername,$username,$password, $username);
  if($conn->connect_error){
    die("Connection Failed: ".$conn->connect_error);
  }




?>

<html>
<head>
  <link rel="stylesheet" href="css/main.css">
</head>
<body>
  <div class="UserCreation">
    <?php
    //Grabbing user id from HTML Form
    $user = $_POST["user_id"];

    //Check if user id already exists in database
    $query = mysqli_query($conn, "SELECT * FROM Users WHERE user_id= '".$user."'");

    if(mysqli_num_rows($query) > 0){
      echo "Attempted User Id already exists<br>Try Again<br>";
      echo "<a href='CreateUser.html'>Go Back To Create User</a>";
    }else{

        //Insert new user into database
        $sql = "INSERT INTO Users(user_id)
        VALUES('".$user."');";

        if($conn->query($sql) === TRUE){
          echo "New record created successfully:";
          echo "<p id='newUserDisplay'>User Id: ".$user;
          echo "<br><a href='CreatePosts.html'>Create Posts</a></p>";
        }else{
          echo "Error: ".$sql. "<br>".$conn->error;
        }
    }

    ?>

  </div>


</body>
</html>
