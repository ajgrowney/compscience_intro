
<?php
/////////////////////////////////////////////////////////////////////////////
///File: saveEventToDB.php
///Author: Kaiser Mittenburg
///Purpose: Save event information to the database.
///Last Modified: 9/17/2017
/////////////////////////////////////////////////////////////////////////////

include 'header.php';

///Decode JSON string from javascript xmlhttprequest
$name = json_decode("$_GET[name]");

///Escape characters not fit for sql statements
$name = mysql_real_escape_string($name);

///Decode JSON string from javascript xmlhttpreqest
$event_name = json_decode("$_GET[event_name]");

///Escape characters not fit for sql statements
$event_name = mysql_real_escape_string($event_name);

///Decode JSON string from javascript xmlhttprequest
$date = json_decode("$_GET[date]");

///For all below, Decode JSON string from the javascript xmlhttprequest
///and escape characters not fit for sql statements
$_0000 = mysql_real_escape_string(json_decode("$_GET[0000]"));
$_0030 = mysql_real_escape_string(json_decode("$_GET[0030]"));
$_0100 = mysql_real_escape_string(json_decode("$_GET[0100]"));
$_0130 = mysql_real_escape_string(json_decode("$_GET[0130]"));
$_0200 = mysql_real_escape_string(json_decode("$_GET[0200]"));
$_0230 = mysql_real_escape_string(json_decode("$_GET[0230]"));
$_0300 = mysql_real_escape_string(json_decode("$_GET[0300]"));
$_0330 = mysql_real_escape_string(json_decode("$_GET[0330]"));
$_0400 = mysql_real_escape_string(json_decode("$_GET[0400]"));
$_0430 = mysql_real_escape_string(json_decode("$_GET[0430]"));
$_0500 = mysql_real_escape_string(json_decode("$_GET[0500]"));
$_0530 = mysql_real_escape_string(json_decode("$_GET[0530]"));
$_0600 = mysql_real_escape_string(json_decode("$_GET[0600]"));
$_0630 = mysql_real_escape_string(json_decode("$_GET[0630]"));
$_0700 = mysql_real_escape_string(json_decode("$_GET[0700]"));
$_0730 = mysql_real_escape_string(json_decode("$_GET[0730]"));
$_0800 = mysql_real_escape_string(json_decode("$_GET[0800]"));
$_0830 = mysql_real_escape_string(json_decode("$_GET[0830]"));
$_0900 = mysql_real_escape_string(json_decode("$_GET[0900]"));
$_0930 = mysql_real_escape_string(json_decode("$_GET[0930]"));
$_1000 = mysql_real_escape_string(json_decode("$_GET[1000]"));
$_1030 = mysql_real_escape_string(json_decode("$_GET[1030]"));
$_1100 = mysql_real_escape_string(json_decode("$_GET[1100]"));
$_1130 = mysql_real_escape_string(json_decode("$_GET[1130]"));
$_1200 = mysql_real_escape_string(json_decode("$_GET[1200]"));
$_1230 = mysql_real_escape_string(json_decode("$_GET[1230]"));
$_1300 = mysql_real_escape_string(json_decode("$_GET[1300]"));
$_1330 = mysql_real_escape_string(json_decode("$_GET[1330]"));
$_1400 = mysql_real_escape_string(json_decode("$_GET[1400]"));
$_1430 = mysql_real_escape_string(json_decode("$_GET[1430]"));
$_1500 = mysql_real_escape_string(json_decode("$_GET[1500]"));
$_1530 = mysql_real_escape_string(json_decode("$_GET[1530]"));
$_1600 = mysql_real_escape_string(json_decode("$_GET[1600]"));
$_1630 = mysql_real_escape_string(json_decode("$_GET[1630]"));
$_1700 = mysql_real_escape_string(json_decode("$_GET[1700]"));
$_1730 = mysql_real_escape_string(json_decode("$_GET[1730]"));
$_1800 = mysql_real_escape_string(json_decode("$_GET[1800]"));
$_1830 = mysql_real_escape_string(json_decode("$_GET[1830]"));
$_1900 = mysql_real_escape_string(json_decode("$_GET[1900]"));
$_1930 = mysql_real_escape_string(json_decode("$_GET[1930]"));
$_2000 = mysql_real_escape_string(json_decode("$_GET[2000]"));
$_2030 = mysql_real_escape_string(json_decode("$_GET[2030]"));
$_2100 = mysql_real_escape_string(json_decode("$_GET[2100]"));
$_2130 = mysql_real_escape_string(json_decode("$_GET[2130]"));
$_2200 = mysql_real_escape_string(json_decode("$_GET[2200]"));
$_2230 = mysql_real_escape_string(json_decode("$_GET[2230]"));
$_2300 = mysql_real_escape_string(json_decode("$_GET[2300]"));
$_2330 = mysql_real_escape_string(json_decode("$_GET[2330]"));



///Sql statement to insert (add) new row with event information into the DB
$sql3 = "INSERT INTO $tbl_name (name, event_name, `date`, `0000`, `0030`, `0100`, `0130`, `0200`, `0230`, `0300`,`0330`,`0400`,`0430`,`0500`,`0530`,`0600`,`0630`,`0700`,`0730`,`0800`,`0830`,`0900`,`0930`,`1000`,`1030`,`1100`,`1130`,`1200`,`1230`,`1300`,`1330`,`1400`,`1430`,`1500`,`1530`,`1600`,`1630`,`1700`,`1730`,`1800`,`1830`,`1900`,`1930`,`2000`,`2030`,`2100`,`2130`,`2200`,`2230`,`2300`,`2330`)
         VALUES ('$name' , '$event_name' , '$date' , '$_0000' , '$_0030' , '$_0100' , '$_0130' , '$_0200' , '$_0230' , '$_0300' , '$_0330' , '$_0400' , '$_0430' , '$_0500' , '$_0530' , '$_0600' , '$_0630' , '$_0700' , '$_0730' , '$_0800' , '$_0830' , '$_0900' , '$_0930' , '$_1000' , '$_1030' , '$_1100' , '$_1130' , '$_1200' , '$_1230' , '$_1300' , '$_1330' , '$_1400' , '$_1430' , '$_1500' , '$_1530' , '$_1600' , '$_1630' , '$_1700' , '$_1730' , '$_1800' , '$_1830' , '$_1900' , '$_1930' , '$_2000' , '$_2030' , '$_2100' , '$_2130' , '$_2200' , '$_2230' , '$_2300' , '$_2330')";

/**
Execute sql statement and echo if it was succesful
*/
if(mysql_query($sql3))
{
    echo "Records inserted successfully.";
}
else
{
    echo "ERROR: Could not execute ." ;
}

?>
