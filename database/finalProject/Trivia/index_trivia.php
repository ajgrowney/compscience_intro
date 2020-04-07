<?php
  $server = "mysql.eecs.ku.edu";
  $username = "a295g044";
  $password = "$3curE.";

  $conn = new mysqli($server,$username,$password,$username);

  if($conn->connect_error){
    printf("Connection failed");
    exit();
  }
  echo '<h1>Test your Sports Knowledge!</h1>';
?>
