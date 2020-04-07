<?php
  include '../database_helper.php';
  $db = open_db();
  $games = get_random_ncaa_tournament_games($db);
  echo '<body>';
  echo "<h1>Test your Sports Knowledge!</h1>";
  echo '<form action="result.php" method="post" id="quiz">';
  foreach ($games as $key=>$game) {
    echo '<h3>Which team won: ' . $game->team1_name . ' or ' . $game->team2_name . ' on ' . $game->day . ' during the ' . $game->season . ' season?' . '</h3>';
    echo '<div>';
    echo '<input type="radio" name="question-' . $key . '-answers" id="question-' . $key . '-answers-A" value="' . $game->team1_id . '" required/>';
    echo '<input type="hidden" name="question-' . $key . '-season" id="question-' . $key . '-answers-A" value="' . $game->season . '"/>';
    echo '<input type="hidden" name="question-' . $key . '-day" id="question-' . $key . '-answers-A" value="' . $game->day . '"/>';
    echo '<label for="question-' . $key . '-answers-A">' . $game->team1_name . '</label>';
    echo '<input type="radio" name="question-' . $key . '-answers" id="question-' . $key . '-answers-B" value="' . $game->team2_id . '" required/>';
    echo '<input type="hidden" name="question-' . $key . '-season" id="question-' . $key . '-answers-A" value="' . $game->season . '"/>';
    echo '<input type="hidden" name="question-' . $key . '-day" id="question-' . $key . '-answers-A" value="' . $game->day . '"/>';
    echo '<label for="question-' . $key . '-answers-B">' . $game->team2_name . '</label>';
    echo '</div>';
  }
  echo '<input type="submit" value="Submit Quiz" />';
  echo '</form>';
  echo '</body>';
  close_db($db);
?>

