<?php

/////////////////////////////////////////////////////////////////////////////
///File: getEventsFromDB.php
///Author: Kaiser Mittenburg
///Purpose: Obtain the event information from the database.
///Last Modified: 9/17/2017
/////////////////////////////////////////////////////////////////////////////

include 'header.php';

///Select all events from the database
$result = mysql_query( "SELECT * FROM $tbl_name");

///Array to send back
$events_arr = [];

///Adds second dimension to events_arr
while ($row = mysql_fetch_assoc($result))
{
   $arr2 = array();
   foreach ($row as $val) $arr2[] = $val;
   $events_arr[] = $arr2;
};

///Make the array available for javascript to decode and use the array.
echo json_encode($events_arr);
 ?>
