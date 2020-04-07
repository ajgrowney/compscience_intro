<?php

//Connecting to mySQL
$servername = "mysql.eecs.ku.edu";
$username = "agrowney";
$password = 'P@$$word123';

$conn = new mysqli($servername,$username,$password, $username);
if($conn->connect_error){
  die("Connection Failed: ".$conn->connect_error);
}
$userList = $_POST["userList"];

?>
<html>
<head>
  <meta charset="utf-8">
  <link rel="stylesheet" href="css/main_viewUserPosts.css">
  <link rel="stylesheet" href="css/header.css">
</head>
<body>
  <div class="header">
    <h1> Simple Message Board </h1>
  </div>
  <?php
    $sql = "SELECT * FROM Posts WHERE author_id = '".$userList."';";
    $result = $conn->query($sql);
    if($result->num_rows > 0){
	echo "<table><th>Post Id</th><th>Post Content</th>";
      while($row = $result->fetch_assoc()){
        echo "<tr><td>".$row['post_id']."</td><td>".$row['content']."</td></tr>";
        }
	echo "</table>";
    }else{
        echo "User has no posts available\n";
    }
   ?>
   <br><a href="index.html">Home Page</a>
</body>
</html>
