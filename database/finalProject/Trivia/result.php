<?php
include '../database_helper.php';

class Answer {
  public $season;
  public $day;
  public $team;
}

$i = 0;
$answers = array();
while ($_POST["question-$i-answers"]) {
  $ans = new Answer();
  $ans->team = $_POST["question-$i-answers"];
  $ans->season = $_POST["question-$i-season"];
  $ans->day = $_POST["question-$i-day"];
  $answers[$i] = $ans;
  $i += 1;
}
echo "<h1>Results!</h1>";
$db = open_db();
$correct = 0;
$false = 0;
foreach($answers as $key=>$ans) {
  $key +=1;
  if (won_ncaa_tournament_game($db,$ans->season,$ans->day,$ans->team)) {
    echo "<div>";
    echo "<h3>Question $key:</h3>";
    echo "<p>CORRRECT</p>";
    echo "</div>";
    $correct += 1;
  } else {
    echo "<div>";
    echo "<h3>Question $key:</h3>";
    echo "<p>FALSE</p>";
    echo "</div>";
    $false += 1;
  }
}
$total = $correct + $false;
echo "<div><h3>Your Score: $correct / $total</h3></div>";
echo '<form action="LeaderBoard.php" method="POST">';
echo '<label>Your Initials<input type="text" name="initials" required></input></label>';
echo '<input type="hidden" name="score" value='.$correct.' />';
echo '<input type="submit">';
echo '</form>';
close_db($db);
?>
