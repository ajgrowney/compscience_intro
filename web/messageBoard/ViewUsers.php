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
</head>
<body>

  <h1>Current Users Table</h1>
  <?php
  $sql = "SELECT * FROM Users";
  $count = 0;
  $result = $conn->query($sql);
  if($result->num_rows > 0){
    echo "<table><th>Count</th><th>User ID</th><tr>";
    while($row = $result->fetch_assoc()){
      $count++;

      echo "<td>".$count."</td><td>";
      echo $row["user_id"]."</td>";
      echo "</tr>";
    }
    echo "</table>";
  }else{
    echo "0 Results";
  }
  ?>
</body>
</html>
