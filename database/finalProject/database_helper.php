<?php
class Game {
  public $team1_id;
  public $team1_name;
  public $team2_id;
  public $team2_name;
  public $season;
  public $day;
}
?>
<?php
function open_db() {
  $db = new mysqli('mysql.eecs.ku.edu', 'a295g044', '$PASSWORD', 'a295g044');
  if ($db->connect_errno) {
    echo "Failed to connect to MySQL: (" . $db->connect_errno . ") " . $db->connect_error;
  }
  return $db;
}

function close_db($db) {
  $db->close();
}

function get_leaderboard($db) {
  echo '<div>';
  $query_board = "SELECT Initials,Score FROM TRIVIALEADERBOARD ORDER BY Score DESC";
  $result = $db->query($query_board);
  if(mysqli_num_rows($result) > 0){
  	echo '<h2 class="leaderboardTitle">Leaderboard</h2>';
  	echo '<table class="leaderboardTable">';
  	echo '<thead class="leaderboardHeader"><tr><th>Players</th><th>Score</th></tr></thead>';
  	while ($player = $result->fetch_assoc()){
  		echo "<tr><td>" . $player['Initials'] . "</td><td>". $player['Score'] ."</td></tr>";
  	}
  	echo '</table>';
  }else{
  	echo '<h2>Be the first to play!</h2>';
  }
  echo '</div>';
  mysqli_free_result($result);
}

function add_leaderboard($db, $initials, $score) {
  $query = "INSERT INTO TRIVIALEADERBOARD (Initials, Score) VALUES ('$initials', '$score')";
  if ($result = $db->query($query)){
  }
  else{
    echo "$db->error";
  }
}
function get_random_ncaa_tournament_games($db) {
  $count = get_table_size($db,"NCAATOURNCOMPACT");
  $size = 10;
  $randoms = strval(rand(1,$count));

  for ($i = 1; $i < $size; $i++) {
    $randoms .= ", " . strval(rand(1,$count));
  }

  $query = "SELECT WTeamID, WT.TeamName, LTeamID, LT.TeamName, Season, DayNum
              FROM NCAATOURNCOMPACT AS TOURN, TEAMS AS WT, TEAMS AS LT
              WHERE
                TOURN.WTeamID = WT.TeamID AND
                TOURN.LTeamID = LT.TeamID AND
                GameID IN ($randoms)
              LIMIT $size;";
  $games = array();
  if ($res = $db->query($query)) {
    while ($data = $res->fetch_row()) {
      $g = new Game();
      if (rand() % 2 == 0) {
        $g->team1_id = $data[0];
        $g->team1_name = $data[1];
        $g->team2_id = $data[2];
        $g->team2_name = $data[3];
      } else {
        $g->team1_id = $data[2];
        $g->team1_name = $data[3];
        $g->team2_id = $data[0];
        $g->team2_name = $data[1];
      }
      $g->season = $data[4];
      $g->day = $data[5];
      $games[] = $g;
    }
    return $games;
  }
}

function won_ncaa_tournament_game($db,$season,$day,$team) {
  $query = "SELECT WTeamID
              FROM NCAATOURNCOMPACT AS TOURN
              WHERE
                Season = $season AND
                DayNum = $day AND
                (WTeamID = $team OR LTeamID = $team);";
  if ($res = $db->query($query)) {
    $data = $res->fetch_row();
    return ($data[0] == $team);
  }
}

function get_table_size($db,$tablename) {
  $query = "SELECT COUNT(*)
              FROM $tablename;";
  if ($res = $db->query($query)) {
    $data = $res->fetch_row();
    return $data[0];
  }
}
?>
