<?php
/////////////////////////////////////////////////////////////////////////////
///File: header.php
///Author: Kaiser Mittenburg
///Purpose: File to incude in all files that need to connect to the database
///Last Modified: 9/17/2017
/////////////////////////////////////////////////////////////////////////////

///Connection Variables

$host="sql9.freemysqlhosting.net"; // Host name
$username="sql9193383"; // Mysql username
$password="5Die3BXFPm"; // Mysql password
$db_name="sql9193383"; // Database name
$tbl_name="Project_1_Table_1"; // Table name

///Connect to the server
$link = mysql_connect("$host", "$username", "$password")or die("cannot connect");

///Select the database, or display error
mysql_select_db("$db_name")or die("cannot select DB");

?>
