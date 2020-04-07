<?php
/////////////////////////////////////////////////////////////////////////////
///File: addAttendeeToEvent.php
///Author: Kaiser Mittenburg
///Purpose: Add a user to the attendee list of a given event
///Last Modified: 9/17/2017
/////////////////////////////////////////////////////////////////////////////

include 'header.php';
include 'getEventsFromDB.php';

///Decode JSON string from javascript xmlhttprequest
$time_arr=json_decode("$_GET[time_array]");

///Decode JSON string from javascript xmlhttprequest
$user_name = json_decode("$_GET[user_name]");

///Escape characters not fit for sql statement
//$user_name = mysql_real_escape_string($user_name);

///Decode JSON string from javascript xmlhttprequest
$name = json_decode("$_GET[name]");

///Escape characters not fit for sql statement
//$name = mysql_real_escape_string($name);

///Decode JSON string from javascript xmlhttprequest
$event_name = json_decode("$_GET[event_name]");

///Escape characters not fit for sql statement
//$event_name = mysql_real_escape_string($event_name);



echo $name; echo $events_arr[0][1]; echo $event_name; echo $events_arr[0][2];
///Cycle thru events and check if the event exists in the database
///$events_arr is obtained from the include of getEventsFromDB.php
for($i = 0; $i < count($events_arr); $i++)
{
  if($name == $events_arr[$i][1] && $event_name == $events_arr[$i][2])
  {
    $user_name = mysql_real_escape_string($user_name);
    $event_name = mysql_real_escape_string($event_name);
    $name = mysql_real_escape_string($name);
    for($j = 0; $j < count($time_arr); $j++)
    {
      echo $time_arr[$j];
      
      ///Sql statement to Update (append) an existing row in the database
      $sql30 = "UPDATE $tbl_name SET `$time_arr[$j]` = concat(`$time_arr[$j]`, '$user_name') WHERE `name` = '$name' AND `event_name` = '$event_name' ";
      ///Execute and check if the sql action was successful
      if(mysql_query($sql30))
      {
          echo "Records inserted successfully.";
      }
      else
      {
          echo "ERROR: Could not execute ." ;
      }

    }
  }
}

?>
