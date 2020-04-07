<?php

//Connecting to mySQL
$servername = "mysql.eecs.ku.edu";
$username = "agrowney";
$password = 'P@$$word123';

$conn = new mysqli($servername,$username,$password, $username);
if($conn->connect_error){
  die("Connection Failed: ".$conn->connect_error);
}

  $postList = $_POST["postList"];

?>

<html>
<head>
  <link rel="stylesheet" href="css/header.css">
</head>
<body>
  <div class="header">
    <h1>Simple Message Board</h1>
  </div>
  <?php
  if(empty($postList)){
    echo "No Posts Selected<br>";
  }else{
    $count = count($postList);

for($i = 0; $i < $count; $i++){
      echo "Deleted Post #".$postList[$i]."<br>";
    }

    for($i = 0; $i < $count; $i++){
      $sql = "DELETE FROM Posts WHERE post_id = '".$postList[$i]."';";
      $result = $conn->query($sql);
    }

  }
   ?>

   <a href="index.html">Home Page</a>
</body>
</html>
