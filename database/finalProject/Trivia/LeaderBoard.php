<html>
<head>
  <title>March Madness Trivia</title>
  <link rel="stylesheet" href="LeaderBoard.css">
</head>
<body>
  <?php
  include '../database_helper.php';
  $db = open_db();

  $initials = $_POST['initials'];
  $score = $_POST['score'];

  add_leaderboard($db,$initials,$score);
  get_leaderboard($db);
  close_db($db);
  ?>
  <div class="buttonContainer">
    <a href="../"><button id="homeButton" class="navButton" >Return Home</button></a>
    <a href="./question.php"><button id="playAgain" class="navButton">Play Again</button></a>
  </div>
</body>
</html>
