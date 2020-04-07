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
  <link rel="stylesheet" href="css/header.css">
</head>
<body>
  <div class="header">
    <h1> Simple Message Board </h1>
  </div>

  <div class = "main_post">
    <?php
    //Grabbing user id and Post content from HTML Form
    $userId = $_POST["userID"];
    $post_content = $_POST["post_content"];
    $post_content = $conn->real_escape_string($post_content);
    //Check if user id already exists in database
    $query = mysqli_query($conn, "SELECT * FROM Users WHERE user_id= '".$userId."'");

    if(mysqli_num_rows($query) == 1){
      //The User ID has a unique match
      //Insert new user into database
      $sql = "INSERT INTO Posts(author_id, content)
      VALUES('".$userId."','".$post_content."');";

      if($conn->query($sql) === TRUE){
        echo "New record created successfully:";
        echo "<p id='newPstUserDisplay'>User Id: ".$userId."</p>";
        echo "<p id='newPstContentDisplay'>Post Content: ".$post_content."</p>";
      }else{
        echo "Error: ".$sql. "<br>".$conn->error;
        echo mysqli_num_rows($query);
      }

    }else{
      echo "Didn't find User ID";

    }

    ?>

  </div>
  <a href="index.html">Home Page</a>

</body>
</html>
