///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///File Name: user.js
///Author: Andrew Growney, Kaiser Mittenburg, Juzer Zarif
///Purpose: Running JavaScript scripts for HTML elements and contains back-end logic
///Last Modified: 09/17/2017
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** Array to store information for all events; populated whenever page loads */
var events_arr;

/**
 * Fetches events info from database and populates events_arr
 * @param {string} path - file name that event info is obtained from
 * @param {function} callback - function that can be defined while calling getEventsFromDB to perform required task
 */
function getEventsFromDB(path, callback)
{
  var request = new XMLHttpRequest();
  request.onreadystatechange = function ()
  {
    if (request.readyState === XMLHttpRequest.DONE)
    {
      if (request.status === 200)
      {
        //console.log(request.responseText); //DEBUGGING
        //alert(request.responseText); //DEBUGGING
        events_arr = JSON.parse(request.responseText);
        callback();
      } else {

      }
    }
  };

    request.open("GET", path, true);
    request.send();
    return request.onreadystatechange();
}

/**
 * Sends and stores user availability information for events to the database
 * @param {string} user_name - The name of the attendee
 * @param {string} creator_name - The name of the event organizer
 * @param {string} event_name - The name of the event
 * @param {Array} time_array - An array with the times the attendee can make it to the event
 */
function pushToDB(user_name, creator_name, event_name, time_array)
{
  //alert(user_name + creator_name + event_name + time_array);
  var request2 = new XMLHttpRequest();
  request2.onreadystatechange = function ()
  {
    if (request2.readyState === XMLHttpRequest.DONE)
    {
      if (request2.status === 200)
      {

      }
      else
      {

      }
    }

  }

    var json = JSON.stringify(time_array);
    //alert(user_name);

    user_name = user_name + ", ";
    //alert(user_name);
    //alert(JSON.stringify(user_name));

    var urlToSendTo2 = "php/addAttendeeToEvent.php?" + "name=" + JSON.stringify(creator_name) + "&event_name=" + JSON.stringify(event_name) + "&user_name=" + JSON.stringify(user_name) + "&time_array=" + json + "&";
    console.log(urlToSendTo2);
    request2.open("GET", urlToSendTo2, true);
    request2.send();
    return request2.onreadystatechange();
}

/**
 * Resets the color of all the buttons for every time interval to its default setting.
 * @param {number} col_num - Index corresponding to a time interval in "time_arr"
 */
function colorReset(col_num){
  if(col_num==0){$("#am1200").css("background-color","#303030"); $("#t0000").css("background-color", "#303030")
  }else if(col_num==1){$("#am1230").css("background-color","#303030"); $("#t0030").css("background-color","#303030");
  }else if(col_num==2){$("#am100").css("background-color","#303030"); $("#t100").css("background-color", "#303030");
  }else if(col_num==3){$("#am130").css("background-color","#303030"); $("#t130").css("background-color", "#303030");
  }else if(col_num==4){$("#am200").css("background-color","#303030"); $("#t200").css("background-color", "#303030");
  }else if(col_num==5){$("#am230").css("background-color","#303030"); $("#t230").css("background-color", "#303030");
  }else if(col_num==6){$("#am300").css("background-color","#303030"); $("#t300").css("background-color", "#303030");
  }else if(col_num==7){$("#am330").css("background-color","#303030"); $("#t330").css("background-color", "#303030");
  }else if(col_num==8){$("#am400").css("background-color","#303030"); $("#t400").css("background-color", "#303030");
  }else if(col_num==9){$("#am430").css("background-color","#303030"); $("#t430").css("background-color", "#303030");
  }else if(col_num==10){$("#am500").css("background-color","#303030"); $("#t500").css("background-color", "#303030");
  }else if(col_num==11){$("#am530").css("background-color","#303030"); $("#t530").css("background-color", "#303030");
  }else if(col_num==12){$("#am600").css("background-color","#303030"); $("#t600").css("background-color", "#303030");
  }else if(col_num==13){$("#am630").css("background-color","#303030"); $("#t630").css("background-color", "#303030");
  }else if(col_num==14){$("#am700").css("background-color","#303030"); $("#t700").css("background-color", "#303030");
  }else if(col_num==15){$("#am730").css("background-color","#303030"); $("#t730").css("background-color", "#303030");
  }else if(col_num==16){$("#am800").css("background-color","#303030"); $("#t800").css("background-color", "#303030");
  }else if(col_num==17){$("#am830").css("background-color","#303030"); $("#t830").css("background-color", "#303030");
  }else if(col_num==18){$("#am900").css("background-color","#303030"); $("#t900").css("background-color", "#303030");
  }else if(col_num==19){$("#am930").css("background-color","#303030"); $("#t930").css("background-color", "#303030");
  }else if(col_num==20){$("#am1000").css("background-color","#303030"); $("#t1000").css("background-color", "#303030");
  }else if(col_num==21){$("#am1030").css("background-color","#303030"); $("#t1030").css("background-color", "#303030");
  }else if(col_num==22){$("#am1100").css("background-color","#303030"); $("#t1100").css("background-color", "#303030");
  }else if(col_num==23){$("#am1130").css("background-color","#303030"); $("#t1130").css("background-color", "#303030");
  }else if(col_num==24){$("#pm1200").css("background-color","#303030"); $("#t1200").css("background-color", "#303030");
  }else if(col_num==25){$("#pm1230").css("background-color","#303030"); $("#t1230").css("background-color", "#303030");
  }else if(col_num==26){$("#pm100").css("background-color","#303030"); $("#t1300").css("background-color", "#303030");
  }else if(col_num==27){$("#pm130").css("background-color","#303030"); $("#t1330").css("background-color", "#303030");
  }else if(col_num==28){$("#pm200").css("background-color","#303030"); $("#t1400").css("background-color", "#303030");
  }else if(col_num==29){$("#pm230").css("background-color","#303030"); $("#t1430").css("background-color", "#303030");
  }else if(col_num==30){$("#pm300").css("background-color","#303030"); $("#t1500").css("background-color", "#303030");
  }else if(col_num==31){$("#pm330").css("background-color","#303030"); $("#t1530").css("background-color", "#303030");
  }else if(col_num==32){$("#pm400").css("background-color","#303030"); $("#t1600").css("background-color", "#303030");
  }else if(col_num==33){$("#pm430").css("background-color","#303030"); $("#t1630").css("background-color", "#303030");
  }else if(col_num==34){$("#pm500").css("background-color","#303030"); $("#t1700").css("background-color", "#303030");
  }else if(col_num==35){$("#pm530").css("background-color","#303030"); $("#t1730").css("background-color", "#303030");
  }else if(col_num==36){$("#pm600").css("background-color","#303030"); $("#t1800").css("background-color", "#303030");
  }else if(col_num==37){$("#pm630").css("background-color","#303030"); $("#t1830").css("background-color", "#303030");
  }else if(col_num==38){$("#pm700").css("background-color","#303030"); $("#t1900").css("background-color", "#303030");
  }else if(col_num==39){$("#pm730").css("background-color","#303030"); $("#t1930").css("background-color", "#303030");
  }else if(col_num==40){$("#pm800").css("background-color","#303030"); $("#t2000").css("background-color", "#303030");
  }else if(col_num==41){$("#pm830").css("background-color","#303030"); $("#t2030").css("background-color", "#303030");
  }else if(col_num==42){$("#pm900").css("background-color","#303030"); $("#t2100").css("background-color", "#303030");
  }else if(col_num==43){$("#pm930").css("background-color","#303030"); $("#t2130").css("background-color", "#303030");
  }else if(col_num==44){$("#pm1000").css("background-color","#303030"); $("#t2200").css("background-color", "#303030");
  }else if(col_num==45){$("#pm1030").css("background-color","#303030"); $("#t2230").css("background-color", "#303030");
  }else if(col_num==46){$("#pm1100").css("background-color","#303030"); $("#t2300").css("background-color", "#303030");
  }else if(col_num==47){$("#pm1130").css("background-color","#303030"); $("#t2330").css("background-color", "#303030");
  }
}

/**
 * Changes color of the button for a time interval from default to green and vice versa when clicked.
 * @param {number} col_num - Index corresponding to a time interval in "time_arr"
 */
function colorChange(col_num){
  if(col_num==0){$("#am1200").css("background-color","#80C468"); $("#t0000").css("background-color", "#80C468");
  }else if(col_num==2){$("#am100").css("background-color","#80C468"); $("#t100").css("background-color", "#80C468");
  }else if(col_num==1){$("#am1230").css("background-color","#80C468"); $("#t0030").css("background-color","#80C468");
  }else if(col_num==4){$("#am200").css("background-color","#80C468"); $("#t200").css("background-color", "#80C468");
  }else if(col_num==3){$("#am130").css("background-color","#80C468"); $("#t130").css("background-color", "#80C468");
  }else if(col_num==6){$("#am300").css("background-color","#80C468"); $("#t300").css("background-color", "#80C468");
  }else if(col_num==5){$("#am230").css("background-color","#80C468"); $("#t230").css("background-color", "#80C468");
  }else if(col_num==8){$("#am400").css("background-color","#80C468"); $("#t400").css("background-color", "#80C468");
  }else if(col_num==7){$("#am330").css("background-color","#80C468"); $("#t330").css("background-color", "#80C468");
  }else if(col_num==10){$("#am500").css("background-color","#80C468"); $("#t500").css("background-color", "#80C468");
  }else if(col_num==9){$("#am430").css("background-color","#80C468"); $("#t430").css("background-color", "#80C468");
  }else if(col_num==12){$("#am600").css("background-color","#80C468"); $("#t600").css("background-color", "#80C468");
  }else if(col_num==11){$("#am530").css("background-color","#80C468"); $("#t530").css("background-color", "#80C468");
  }else if(col_num==14){$("#am700").css("background-color","#80C468"); $("#t700").css("background-color", "#80C468");
  }else if(col_num==13){$("#am630").css("background-color","#80C468"); $("#t630").css("background-color", "#80C468");
  }else if(col_num==16){$("#am800").css("background-color","#80C468"); $("#t800").css("background-color", "#80C468");
  }else if(col_num==15){$("#am730").css("background-color","#80C468"); $("#t730").css("background-color", "#80C468");
  }else if(col_num==18){$("#am900").css("background-color","#80C468"); $("#t900").css("background-color", "#80C468");
  }else if(col_num==17){$("#am830").css("background-color","#80C468"); $("#t830").css("background-color", "#80C468");
  }else if(col_num==20){$("#am1000").css("background-color","#80C468"); $("#t1000").css("background-color", "#80C468");
  }else if(col_num==19){$("#am930").css("background-color","#80C468"); $("#t930").css("background-color", "#80C468");
  }else if(col_num==22){$("#am1100").css("background-color","#80C468"); $("#t1100").css("background-color", "#80C468");
  }else if(col_num==21){$("#am1030").css("background-color","#80C468"); $("#t1030").css("background-color", "#80C468");
  }else if(col_num==23){$("#am1130").css("background-color","#80C468"); $("#t1130").css("background-color", "#80C468");
  }else if(col_num==24){$("#pm1200").css("background-color","#80C468"); $("#t1200").css("background-color", "#80C468");
  }else if(col_num==25){$("#pm1230").css("background-color","#80C468"); $("#t1230").css("background-color", "#80C468");
  }else if(col_num==26){$("#pm100").css("background-color","#80C468"); $("#t1300").css("background-color", "#80C468");
  }else if(col_num==27){$("#pm130").css("background-color","#80C468"); $("#t1330").css("background-color", "#80C468");
  }else if(col_num==28){$("#pm200").css("background-color","#80C468"); $("#t1400").css("background-color", "#80C468");
  }else if(col_num==29){$("#pm230").css("background-color","#80C468"); $("#t1430").css("background-color", "#80C468");
  }else if(col_num==30){$("#pm300").css("background-color","#80C468"); $("#t1500").css("background-color", "#80C468");
  }else if(col_num==31){$("#pm330").css("background-color","#80C468"); $("#t1530").css("background-color", "#80C468");
  }else if(col_num==32){$("#pm400").css("background-color","#80C468"); $("#t1600").css("background-color", "#80C468");
  }else if(col_num==33){$("#pm430").css("background-color","#80C468"); $("#t1630").css("background-color", "#80C468");
  }else if(col_num==34){$("#pm500").css("background-color","#80C468"); $("#t1700").css("background-color", "#80C468");
  }else if(col_num==35){$("#pm530").css("background-color","#80C468"); $("#t1730").css("background-color", "#80C468");
  }else if(col_num==36){$("#pm600").css("background-color","#80C468"); $("#t1800").css("background-color", "#80C468");
  }else if(col_num==37){$("#pm630").css("background-color","#80C468"); $("#t1830").css("background-color", "#80C468");
  }else if(col_num==38){$("#pm700").css("background-color","#80C468"); $("#t1900").css("background-color", "#80C468");
  }else if(col_num==39){$("#pm730").css("background-color","#80C468"); $("#t1930").css("background-color", "#80C468");
  }else if(col_num==40){$("#pm800").css("background-color","#80C468"); $("#t2000").css("background-color", "#80C468");
  }else if(col_num==41){$("#pm830").css("background-color","#80C468"); $("#t2030").css("background-color", "#80C468");
  }else if(col_num==42){$("#pm900").css("background-color","#80C468"); $("#t2100").css("background-color", "#80C468");
  }else if(col_num==43){$("#pm930").css("background-color","#80C468"); $("#t2130").css("background-color", "#80C468");
  }else if(col_num==44){$("#pm1000").css("background-color","#80C468"); $("#t2200").css("background-color", "#80C468");
  }else if(col_num==45){$("#pm1030").css("background-color","#80C468"); $("#t2230").css("background-color", "#80C468");
  }else if(col_num==46){$("#pm1100").css("background-color","#80C468"); $("#t2300").css("background-color", "#80C468");
  }else if(col_num==47){$("#pm1130").css("background-color","#80C468"); $("#t2330 ").css("background-color", "#80C468");
  }
}

/**
 * Creates a 12-hour mode time selection table with every 30-minute interval represented by a button. Only time intervals with an event going on have enabled buttons. Calls function "updateArr" to update "tarr".
 * @param {number} n - Row number of event in the database
 * @param {Array} tarr - Array to store the time intervals a user can attend the event
 */
function makeTable12(n, tarr)
{
  $("#user_table_12").html(
    "<center>Event Schedule</center><br>"+
    "<table id='rev_table'>"+
    "<tr>"+
    "<td><p id = '1200am'><button type = 'button' disabled>12:00am</button></p></td>"+
    "<td><p id = '1230am'><button type = 'button' disabled>12:30am</button></p></td>"+
    "<td><p id = '100am'><button type = 'button' disabled>1:00am</button></p></td>"+
    "<td><p id = '130am'><button type = 'button' disabled>1:30am</button></p></td>"+
    "<td><p id = '200am'><button type = 'button' disabled>2:00am</button></p></td>"+
    "<td><p id = '230am'><button type = 'button' disabled>2:30am</button></p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '300am'><button type = 'button' disabled>3:00am</button></p></td>"+
    "<td><p id = '330am'><button type = 'button' disabled>3:30am</button></p></td>"+
    "<td><p id = '400am'><button type = 'button' disabled>4:00am</button></p></td>"+
    "<td><p id = '430am'><button type = 'button' disabled>4:30am</button></p></td>"+
    "<td><p id = '500am'><button type = 'button' disabled>5:00am</button></p></td>"+
    "<td><p id = '530am'><button type = 'button' disabled>5:30am</button></p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '600am'><button type = 'button' disabled>6:00am</button></p></td>"+
    "<td><p id = '630am'><button type = 'button' disabled>6:30am</button></p></td>"+
    "<td><p id = '700am'><button type = 'button' disabled>7:00am</button></p></td>"+
    "<td><p id = '730am'><button type = 'button' disabled>7:30am</button></p></td>"+
    "<td><p id = '800am'><button type = 'button' disabled>8:00am</button></p></td>"+
    "<td><p id = '830am'><button type = 'button' disabled>8:30am</button></p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '900am'><button type = 'button' disabled>9:00am</button></p></td>"+
    "<td><p id = '930am'><button type = 'button' disabled>9:30am</button></p></td>"+
    "<td><p id = '1000am'><button type = 'button' disabled>10:00am</button></p></td>"+
    "<td><p id = '1030am'><button type = 'button' disabled>10:30am</button></p></td>"+
    "<td><p id = '1100am'><button type = 'button' disabled>11:00am</button></p></td>"+
    "<td><p id = '1130am'><button type = 'button' disabled>11:30am</button></p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '1200pm'><button type = 'button' disabled>12:00pm</button></p></td>"+
    "<td><p id = '1230pm'><button type = 'button' disabled>12:30pm</button></p></td>"+
    "<td><p id = '100pm'><button type = 'button' disabled>1:00pm</button></p></td>"+
    "<td><p id = '130pm'><button type = 'button' disabled>1:30pm</button></p></td>"+
    "<td><p id = '200pm'><button type = 'button' disabled>2:00pm</button></p></td>"+
    "<td><p id = '230pm'><button type = 'button' disabled>2:30pm</button></p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '300pm'><button type = 'button' disabled>3:00pm</button></p></td>"+
    "<td><p id = '330pm'><button type = 'button' disabled>3:30pm</button></p></td>"+
    "<td><p id = '400pm'><button type = 'button' disabled>4:00pm</button></p></td>"+
    "<td><p id = '430pm'><button type = 'button' disabled>4:30pm</button></p></td>"+
    "<td><p id = '500pm'><button type = 'button' disabled>5:00pm</button></p></td>"+
    "<td><p id = '530pm'><button type = 'button' disabled>5:30pm</button></p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '600pm'><button type = 'button' disabled>6:00pm</button></p></td>"+
    "<td><p id = '630pm'><button type = 'button' disabled>6:30pm</button></p></td>"+
    "<td><p id = '700pm'><button type = 'button' disabled>7:00pm</button></p></td>"+
    "<td><p id = '730pm'><button type = 'button' disabled>7:30pm</button></p></td>"+
    "<td><p id = '800pm'><button type = 'button' disabled>8:00pm</button></p></td>"+
    "<td><p id = '830pm'><button type = 'button' disabled>8:30pm</button></p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '900pm'><button type = 'button' disabled>9:00pm</button></p></td>"+
    "<td><p id = '930pm'><button type = 'button' disabled>9:30pm</button></p></td>"+
    "<td><p id = '1000pm'><button type = 'button' disabled>10:00pm</button></p></td>"+
    "<td><p id = '1030pm'><button type = 'button' disabled>10:30pm</button></p></td>"+
    "<td><p id = '1100pm'><button type = 'button' disabled>11:00pm</button></p></td>"+
    "<td><p id = '1130pm'><button type = 'button' disabled>11:30pm</button></p></td>"+
    "</tr>"+
    "</table>"
  );

  for(let i=4; i<52; i++)
  {
    let att = events_arr[n][i];
    console.log(att);
    switch(i)
    {
      case 4:
        if(att != "0"){$("#1200am").html($("<button type = 'button' id = 'am1200'>12:00am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 5:
        if(att != "0"){$("#1230am").html($("<button type = 'button' id = 'am1230'>12:30am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 6:
        if(att != "0"){$("#100am").html($("<button type = 'button' id = 'am100'>1:00am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 7:
        if(att != "0"){$("#130am").html($("<button type = 'button' id = 'am130'>1:30am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 8:
        if(att != "0"){$("#200am").html($("<button type = 'button' id = 'am200'>2:00am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 9:
        if(att != "0"){$("#230am").html($("<button type = 'button' id = 'am230'>2:30am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 10:
        if(att != "0"){$("#300am").html($("<button type = 'button' id = 'am300'>3:00am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 11:
        if(att != "0"){$("#330am").html($("<button type = 'button' id = 'am330'>3:30am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 12:
        if(att != "0"){$("#400am").html($("<button type = 'button' id = 'am400'>4:00am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 13:
        if(att != "0"){$("#430am").html($("<button type = 'button' id = 'am430'>4:30am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 14:
        if(att != "0"){$("#500am").html($("<button type = 'button' id = 'am500'>5:00am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 15:
        if(att != "0"){$("#530am").html($("<button type = 'button' id = 'am530'>5:30am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 16:
        if(att != "0"){$("#600am").html($("<button type = 'button' id = 'am600'>6:00am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 17:
        if(att != "0"){$("#630am").html($("<button type = 'button' id = 'am630'>6:30am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 18:
        if(att != "0"){$("#700am").html($("<button type = 'button' id = 'am700'>7:00am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 19:
        if(att != "0"){$("#730am").html($("<button type = 'button' id = 'am730'>7:30am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 20:
        if(att != "0"){$("#800am").html($("<button type = 'button' id = 'am800'>8:00am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 21:
        if(att != "0"){$("#830am").html($("<button type = 'button' id = 'am830'>8:30am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 22:
        if(att != "0"){$("#900am").html($("<button type = 'button' id = 'am900'>9:00am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 23:
        if(att != "0"){$("#930am").html($("<button type = 'button' id = 'am930'>9:30am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 24:
        if(att != "0"){$("#1000am").html($("<button type = 'button' id = 'am1000'>10:00am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 25:
        if(att != "0"){$("#1030am").html($("<button type = 'button' id = 'am1030'>10:30am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 26:
        if(att != "0"){$("#1100am").html($("<button type = 'button' id = 'am1100'>11:00am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 27:
        if(att != "0"){$("#1130am").html($("<button type = 'button' id = 'am1130'>11:30am</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 28:
        if(att != "0"){$("#1200pm").html($("<button type = 'button' id = 'pm1200'>12:00pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 29:
        if(att != "0"){$("#1230pm").html($("<button type = 'button' id = 'pm1230'>12:30pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 30:
        if(att != "0"){$("#100pm").html($("<button type = 'button' id = 'pm100'>1:00pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 31:
        if(att != "0"){$("#130pm").html($("<button type = 'button' id = 'pm130'>1:30pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 32:
        if(att != "0"){$("#200pm").html($("<button type = 'button' id = 'pm200'>2:00pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 33:
        if(att != "0"){$("#230pm").html($("<button type = 'button' id = 'pm230'>2:30pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 34:
        if(att != "0"){$("#300pm").html($("<button type = 'button' id = 'pm300'>3:00pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 35:
        if(att != "0"){$("#330pm").html($("<button type = 'button' id = 'pm330'>3:30pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 36:
        if(att != "0"){$("#400pm").html($("<button type = 'button' id = 'pm400'>4:00pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 37:
        if(att != "0"){$("#430pm").html($("<button type = 'button' id = 'pm430'>4:30pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 38:
        if(att != "0"){$("#500pm").html($("<button type = 'button' id = 'pm500'>5:00pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 39:
        if(att != "0"){$("#530pm").html($("<button type = 'button' id = 'pm530'>5:30pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 40:
        if(att != "0"){$("#600pm").html($("<button type = 'button' id = 'pm600'>6:00pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 41:
        if(att != "0"){$("#630pm").html($("<button type = 'button' id = 'pm630'>6:30pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 42:
        if(att != "0"){$("#700pm").html($("<button type = 'button' id = 'pm700'>7:00pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 43:
        if(att != "0"){$("#730pm").html($("<button type = 'button' id = 'pm730'>7:30pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 44:
        if(att != "0"){$("#800pm").html($("<button type = 'button' id = 'pm800'>8:00pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 45:
        if(att != "0"){$("#830pm").html($("<button type = 'button' id = 'pm830'>8:30pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 46:
        if(att != "0"){$("#900pm").html($("<button type = 'button' id = 'pm900'>9:00pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 47:
        if(att != "0"){$("#930pm").html($("<button type = 'button' id = 'pm930'>9:30pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 48:
        if(att != "0"){$("#1000pm").html($("<button type = 'button' id = 'pm1000'>10:00pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 49:
        if(att != "0"){$("#1030pm").html($("<button type = 'button' id = 'pm1030'>10:30pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 50:
        if(att != "0"){$("#1100pm").html($("<button type = 'button' id = 'pm1100'>11:00pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 51:
        if(att != "0"){$("#1130pm").html($("<button type = 'button' id = 'pm1130'>11:30pm</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      default:
        break;
    }
  }
}

/**
 * Creates a 24-hour mode time selection table with every 30-minute interval represented by a button. Only time intervals with an event going on have enabled buttons. Calls function "updateArr" to update "tarr".
 * @param {number} n - Row number of event in the database
 * @param {Array} tarr - Array to store the time intervals a user can attend the event
 */
function makeTable24(n, tarr)
{

  $("#user_table_24").html(
    "<center>Event Schedule</center><br>"+
    "<table id='rev_table'>"+
    "<tr>"+
    "<td><p id = '0000'><button type = 'button' disabled>00:00</button></p></td>"+
    "<td><p id = '0030'><button type = 'button' disabled>00:30</button></p></td>"+
    "<td><p id = '100'><button type = 'button' disabled>1:00</button></p></td>"+
    "<td><p id = '130'><button type = 'button' disabled>1:30</button></p></td>"+
    "<td><p id = '200'><button type = 'button' disabled>2:00</button></p></td>"+
    "<td><p id = '230'><button type = 'button' disabled>2:30</button></p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '300'><button type = 'button' disabled>3:00</button></p></td>"+
    "<td><p id = '330'><button type = 'button' disabled>3:30</button></p></td>"+
    "<td><p id = '400'><button type = 'button' disabled>4:00</button></p></td>"+
    "<td><p id = '430'><button type = 'button' disabled>4:30</button></p></td>"+
    "<td><p id = '500'><button type = 'button' disabled>5:00</button></p></td>"+
    "<td><p id = '530'><button type = 'button' disabled>5:30</button></p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '600'><button type = 'button' disabled>6:00</button></p></td>"+
    "<td><p id = '630'><button type = 'button' disabled>6:30</button></p></td>"+
    "<td><p id = '700'><button type = 'button' disabled>7:00</button></p></td>"+
    "<td><p id = '730'><button type = 'button' disabled>7:30</button></p></td>"+
    "<td><p id = '800'><button type = 'button' disabled>8:00</button></p></td>"+
    "<td><p id = '830'><button type = 'button' disabled>8:30</button></p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '900'><button type = 'button' disabled>9:00</button></p></td>"+
    "<td><p id = '930'><button type = 'button' disabled>9:30</button></p></td>"+
    "<td><p id = '1000'><button type = 'button' disabled>10:00</button></p></td>"+
    "<td><p id = '1030'><button type = 'button' disabled>10:30</button></p></td>"+
    "<td><p id = '1100'><button type = 'button' disabled>11:00</button></p></td>"+
    "<td><p id = '1130'><button type = 'button' disabled>11:30</button></p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '1200'><button type = 'button' disabled>12:00</button></p></td>"+
    "<td><p id = '1230'><button type = 'button' disabled>12:30</button></p></td>"+
    "<td><p id = '1300'><button type = 'button' disabled>13:00</button></p></td>"+
    "<td><p id = '1330'><button type = 'button' disabled>13:30</button></p></td>"+
    "<td><p id = '1400'><button type = 'button' disabled>14:00</button></p></td>"+
    "<td><p id = '1430'><button type = 'button' disabled>14:30</button></p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '1500'><button type = 'button' disabled>15:00</button></p></td>"+
    "<td><p id = '1530'><button type = 'button' disabled>15:30</button></p></td>"+
    "<td><p id = '1600'><button type = 'button' disabled>16:00</button></p></td>"+
    "<td><p id = '1630'><button type = 'button' disabled>16:30</button></p></td>"+
    "<td><p id = '1700'><button type = 'button' disabled>17:00</button></p></td>"+
    "<td><p id = '1730'><button type = 'button' disabled>17:30</button></p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '1800'><button type = 'button' disabled>18:00</button></p></td>"+
    "<td><p id = '1830'><button type = 'button' disabled>18:30</button></p></td>"+
    "<td><p id = '1900'><button type = 'button' disabled>19:00</button></p></td>"+
    "<td><p id = '1930'><button type = 'button' disabled>19:30</button></p></td>"+
    "<td><p id = '2000'><button type = 'button' disabled>20:00</button></p></td>"+
    "<td><p id = '2030'><button type = 'button' disabled>20:30</button></p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '2100'><button type = 'button' disabled>21:00</button></p></td>"+
    "<td><p id = '2130'><button type = 'button' disabled>21:30</button></p></td>"+
    "<td><p id = '2200'><button type = 'button' disabled>22:00</button></p></td>"+
    "<td><p id = '2230'><button type = 'button' disabled>22:30</button></p></td>"+
    "<td><p id = '2300'><button type = 'button' disabled>23:00</button></p></td>"+
    "<td><p id = '2330'><button type = 'button' disabled>23:30</button></p></td>"+
    "</tr>"+
    "</table>"
  );

  for(let i=4; i<52; i++)
  {
    let att = events_arr[n][i];
    console.log(att);
    switch(i)
    {
      case 4:
        if(att != "0"){$("#0000").html($("<button type = 'button' id = 't0000'>00:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 5:
        if(att != "0"){$("#0030").html($("<button type = 'button' id = 't0030'>00:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 6:
        if(att != "0"){$("#100").html($("<button type = 'button' id = 't100'>1:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 7:
        if(att != "0"){$("#130").html($("<button type = 'button' id = 't130'>1:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 8:
        if(att != "0"){$("#200").html($("<button type = 'button' id = 't200'>2:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 9:
        if(att != "0"){$("#230").html($("<button type = 'button' id = 't230'>2:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 10:
        if(att != "0"){$("#300").html($("<button type = 'button' id = 't300'>3:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 11:
        if(att != "0"){$("#330").html($("<button type = 'button' id = 't330'>3:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 12:
        if(att != "0"){$("#400").html($("<button type = 'button' id = 't400'>4:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 13:
        if(att != "0"){$("#430").html($("<button type = 'button' id = 't430'>4:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 14:
        if(att != "0"){$("#500").html($("<button type = 'button' id = 't500'>5:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 15:
        if(att != "0"){$("#530").html($("<button type = 'button' id = 't530'>5:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 16:
        if(att != "0"){$("#600").html($("<button type = 'button' id = 't600'>6:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 17:
        if(att != "0"){$("#630").html($("<button type = 'button' id = 't630'>6:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 18:
        if(att != "0"){$("#700").html($("<button type = 'button' id = 't700'>7:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 19:
        if(att != "0"){$("#730").html($("<button type = 'button' id = 't730'>7:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 20:
        if(att != "0"){$("#800").html($("<button type = 'button' id = 't800'>8:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 21:
        if(att != "0"){$("#830").html($("<button type = 'button' id = 't830'>8:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 22:
        if(att != "0"){$("#900").html($("<button type = 'button' id = 't900'>9:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 23:
        if(att != "0"){$("#930").html($("<button type = 'button' id = 't930'>9:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 24:
        if(att != "0"){$("#1000").html($("<button type = 'button' id = 't1000'>10:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 25:
        if(att != "0"){$("#1030").html($("<button type = 'button' id = 't1030'>10:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 26:
        if(att != "0"){$("#1100").html($("<button type = 'button' id = 't1100'>11:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 27:
        if(att != "0"){$("#1130").html($("<button type = 'button' id = 't1130'>11:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 28:
        if(att != "0"){$("#1200").html($("<button type = 'button' id = 't1200'>12:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 29:
        if(att != "0"){$("#1230").html($("<button type = 'button' id = 't1230'>12:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 30:
        if(att != "0"){$("#1300").html($("<button type = 'button' id = 't1300'>13:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 31:
        if(att != "0"){$("#1330").html($("<button type = 'button' id = 't1330'>13:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 32:
        if(att != "0"){$("#1400").html($("<button type = 'button' id = 't1400'>14:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 33:
        if(att != "0"){$("#1430").html($("<button type = 'button' id = 't1430'>14:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 34:
        if(att != "0"){$("#1500").html($("<button type = 'button' id = 't1500'>15:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 35:
        if(att != "0"){$("#1530").html($("<button type = 'button' id = 't1530'>15:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 36:
        if(att != "0"){$("#1600").html($("<button type = 'button' id = 't1600'>16:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 37:
        if(att != "0"){$("#1630").html($("<button type = 'button' id = 't1630'>16:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 38:
        if(att != "0"){$("#1700").html($("<button type = 'button' id = 't1700'>17:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 39:
        if(att != "0"){$("#1730").html($("<button type = 'button' id = 't1730'>17:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 40:
        if(att != "0"){$("#1800").html($("<button type = 'button' id = 't1800'>18:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 41:
        if(att != "0"){$("#1830").html($("<button type = 'button' id = 't1830'>18:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 42:
        if(att != "0"){$("#1900").html($("<button type = 'button' id = 't1900'>19:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 43:
        if(att != "0"){$("#1930").html($("<button type = 'button' id = 't1930'>19:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 44:
        if(att != "0"){$("#2000").html($("<button type = 'button' id = 't2000'>20:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 45:
        if(att != "0"){$("#2030").html($("<button type = 'button' id = 't2030'>20:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 46:
        if(att != "0"){$("#2100").html($("<button type = 'button' id = 't2100'>21:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 47:
        if(att != "0"){$("#2130").html($("<button type = 'button' id = 't2130'>21:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 48:
        if(att != "0"){$("#2200").html($("<button type = 'button' id = 't2200'>22:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 49:
        if(att != "0"){$("#2230").html($("<button type = 'button' id = 't2230'>22:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 50:
        if(att != "0"){$("#2300").html($("<button type = 'button' id = 't2300'>23:00</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      case 51:
        if(att != "0"){$("#2330").html($("<button type = 'button' id = 't2330'>23:30</button>").click(function(){updateArr(n,i,tarr);}));}
        break;
      default:
        break;
    }
  }
}

/**
 * Displays all events in the databse as individual buttons (with event overview). Buttons call function "showInfo" on click to display event information.
 * @param {object} form - HTML form element that takes user input for Attendee Name
 */
function showAllEvents(form)
{
  let name = form.name.value;
  if(name=="")
  {
    alert("All fields are mandatory");
  }
  else
  {
    form.reset();
    $("#name_form").hide();
    $("#form_replace").show();
    $("#event_list").empty();
    for(let i=0; i<events_arr.length; i++)
    {

      $("<button type='button'> <b>Event</b>:<br>"+events_arr[i][2]+"<br> <b>Organizer</b>:<br>"+events_arr[i][1]+"</button>")
        .click(function(){ showInfo(i,name);})
        .appendTo(document.getElementById("event_list"));
        $("#event_list").show();
    }
  }
}

/**
 * Displays event information and calls "makeTable12" and "makeTable24" to populate time tables and allow attendee to RSVP for the event. Collects availability info for attendee and passes it to "pushToDB"
 * @param {number} i - Row number of the event in the database
 * @param {string} name - The name of the attendee
 */
function showInfo(i, name)
{
  if(name == events_arr[i][1])
  {
    $("#organizer_error").dialog();
  }
  else
  {
    $("#event_info").html(
      "Event Name: &nbsp"+events_arr[i][2]+"<br>"+
      "Organizer Name: &nbsp"+events_arr[i][1]+"<br>"+
      "Date: &nbsp"+events_arr[i][3]+"<br>"
    );
    $("#time_switch").empty();
    let time_arr = [];
    $("<button type = 'button' name = '12_time_select' id = 'time_select_12'>12 Hour Format</button>")
      .click(function(){
        time_arr.splice(0);
        for(let i=0; i<48; i++)
        {
          colorReset(i);
        }
        $("#user_table_24").hide();
        $("#user_table_12").toggle();
      })
      .appendTo(document.getElementById("time_switch"));
    $("<button type = 'button' name = '24_time_select' id = 'time_select_24'>24 Hour Format</button>")
      .click(function(){
        time_arr.splice(0);
        for(let i=0; i<48; i++)
        {
          colorReset(i);
        }
        $("#user_table_12").hide();
        $("#user_table_24").toggle();
      })
      .appendTo(document.getElementById("time_switch"));
    makeTable12(i, time_arr);
    makeTable24(i, time_arr);
    $("#time_select_24").show();
    $("#time_select_24").show();
    $("#event_time").show();
    $("#user_table_12").show();
    $("#user_table_24").hide();

    $("#time_submit").html($("<button type = 'button'>Submit</button>").click(function()
      {
        pushToDB(name, events_arr[i][1], events_arr[i][2], time_arr);
        $("#user_table_12").empty().hide();
        $("#user_table_24").empty().hide();
        $("#time_switch").empty();
        $("#event_time").hide();
        $("#event_info").empty().hide();
        $("#time_submit").empty();
      }));
    }
}

/**
 * Displays events for a specified date as individual buttons (with event overview). Buttons call function "showInfo" on click to display event information.
 * @param {object} form - HTML form element that takes user input for Attendee Name and Event Date
 */
function getData(form)
{
  let name = form.event_name.value;
  let date = form.event_date.value;
  if(date == "" || name == "")
  {
    alert("All fields are mandatory!");
  }
  else
  {
    form.reset();
    $("#date_form").hide();
    $("#form_replace").show();
    for(let i=0; i<events_arr.length; i++)
    {
      if(events_arr[i][3] == date)
      {
        $("<button type='button'> Event:<br>"+events_arr[i][2]+"<br> Organizer:<br>"+events_arr[i][1]+"</button>")
          .click(function(){ showInfo(i,name);})
          .appendTo(document.getElementById("event_list"));
        $("#event_list").show();
      }
    }
  }
}

/**
 * Updates availability information for an attendee for a specific 30-minute time interval determined by the event attribute column number in the database, and adds it to "arr"
 * @param {number} i - Row number of the event in the database
 * @param {number} j - Column number for the event attribute in the database
 * @param {Array} arr - Array to store the time intervals a user can attend the event
 */
function updateArr(i, j, arr)
{
  let check = false;
  switch(j)
  {
    case 4:
      check = false;
      if(arr.length == 0){arr.push("0000"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0000"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0000"); colorChange(j-4);}}
      break;
    case 5:
    check = false;
    if(arr.length == 0){arr.push("0030"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0030"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0030"); colorChange(j-4);}}
      break;
    case 6:
    check = false;
    if(arr.length == 0){arr.push("0100"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0100"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0100"); colorChange(j-4);}}
      break;
    case 7:
    check = false;
    if(arr.length == 0){arr.push("0130"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0130"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0130"); colorChange(j-4);}}
      break;
    case 8:
    check = false;
    if(arr.length == 0){arr.push("0200"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0200"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0200"); colorChange(j-4);}}
      break;
    case 9:
    check = false;
    if(arr.length == 0){arr.push("0230"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0230"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0230"); colorChange(j-4);}}
      break;
    case 10:
    check = false;
    if(arr.length == 0){arr.push("0300"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0300"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0300"); colorChange(j-4);}}
      break;
    case 11:
    check = false;
    if(arr.length == 0){arr.push("0330"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0330"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0330"); colorChange(j-4);}}
      break;
    case 12:
    check = false;
    if(arr.length == 0){arr.push("0400"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0400"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0400"); colorChange(j-4);}}
      break;
    case 13:
    check = false;
    if(arr.length == 0){arr.push("0430"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0430"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0430"); colorChange(j-4);}}
      break;
    case 14:
    check = false;
    if(arr.length == 0){arr.push("0500"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0500"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0500"); colorChange(j-4);}}
      break;
    case 15:
    check = false;
    if(arr.length == 0){arr.push("0530"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0530"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0530"); colorChange(j-4);}}
      break;
    case 16:
    check = false;
    if(arr.length == 0){arr.push("0600"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0600"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0600"); colorChange(j-4);}}
      break;
    case 17:
    check = false;
    if(arr.length == 0){arr.push("0630"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0630"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0630"); colorChange(j-4);}}
      break;
    case 18:
    check = false;
    if(arr.length == 0){arr.push("0700"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0700"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0700"); colorChange(j-4);}}
      break;
    case 19:
    check = false;
    if(arr.length == 0){arr.push("0730"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0730"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0730"); colorChange(j-4);}}
      break;
    case 20:
    check = false;
    if(arr.length == 0){arr.push("0800"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0800"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0800"); colorChange(j-4);}}
      break;
    case 21:
    check = false;
    if(arr.length == 0){arr.push("0830"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0830"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0830"); colorChange(j-4);}}
      break;
    case 22:
    check = false;
    if(arr.length == 0){arr.push("0900"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0900"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0900"); colorChange(j-4);}}
      break;
    case 23:
    check = false;
    if(arr.length == 0){arr.push("0930"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "0930"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("0930"); colorChange(j-4);}}
      break;
    case 24:
    check = false;
    if(arr.length == 0){arr.push("1000"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1000"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1000"); colorChange(j-4);}}
      break;
    case 25:
    check = false;
    if(arr.length == 0){arr.push("1030"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1030"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1030"); colorChange(j-4);}}
      break;
    case 26:
    check = false;
    if(arr.length == 0){arr.push("1100"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1100"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1100"); colorChange(j-4);}}
      break;
    case 27:
    check = false;
    if(arr.length == 0){arr.push("1130"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1130"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1130"); colorChange(j-4);}}
      break;
    case 28:
    check = false;
    if(arr.length == 0){arr.push("1200"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1200"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1200"); colorChange(j-4);}}
      break;
    case 29:
    check = false;
    if(arr.length == 0){arr.push("1230"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1230"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1230"); colorChange(j-4);}}
      break;
    case 30:
    check = false;
    if(arr.length == 0){arr.push("1300"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1300"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1300"); colorChange(j-4);}}
      break;
    case 31:
    check = false;
    if(arr.length == 0){arr.push("1330"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1330"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1330"); colorChange(j-4);}}
      break;
    case 32:
    check = false;
    if(arr.length == 0){arr.push("1400"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1400"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1400"); colorChange(j-4);}}
      break;
    case 33:
    check = false;
    if(arr.length == 0){arr.push("1430"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1430"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1430"); colorChange(j-4);}}
      break;
    case 34:
    check = false;
    if(arr.length == 0){arr.push("1500"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1500"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1500"); colorChange(j-4);}}
      break;
    case 35:
    check = false;
    if(arr.length == 0){arr.push("1530"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1530"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1530"); colorChange(j-4);}}
      break;
    case 36:
    check = false;
    if(arr.length == 0){arr.push("1600"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1600"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1600"); colorChange(j-4);}}
      break;
    case 37:
    check = false;
    if(arr.length == 0){arr.push("1630"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1630"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1630"); colorChange(j-4);}}
      break;
    case 38:
    check = false;
    if(arr.length == 0){arr.push("1700"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1700"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1700"); colorChange(j-4);}}
      break;
    case 39:
    check = false;
    if(arr.length == 0){arr.push("1730"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1730"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1730"); colorChange(j-4);}}
      break;
    case 40:
    check = false;
    if(arr.length == 0){arr.push("1800"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1800"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1800"); colorChange(j-4);}}
      break;
    case 41:
    check = false;
    if(arr.length == 0){arr.push("1830"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1830"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1830"); colorChange(j-4);}}
      break;
    case 42:
    check = false;
    if(arr.length == 0){arr.push("1900"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1900"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1900"); colorChange(j-4);}}
      break;
    case 43:
    check = false;
    if(arr.length == 0){arr.push("1930"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "1930"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("1930"); colorChange(j-4);}}
      break;
    case 44:
    check = false;
    if(arr.length == 0){arr.push("2000"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "2000"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("2000"); colorChange(j-4);}}
      break;
    case 45:
    check = false;
    if(arr.length == 0){arr.push("2030"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "2030"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("2030"); colorChange(j-4);}}
      break;
    case 46:
    check = false;
    if(arr.length == 0){arr.push("2100"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "2100"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("2100"); colorChange(j-4);}}
      break;
    case 47:
    check = false;
    if(arr.length == 0){arr.push("2130"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "2130"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("2130"); colorChange(j-4);}}
      break;
    case 48:
    check = false;
    if(arr.length == 0){arr.push("2200"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "2200"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("2200"); colorChange(j-4);}}
      break;
    case 49:
    check = false;
    if(arr.length == 0){arr.push("2230"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "2230"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("2230"); colorChange(j-4);}}
      break;
    case 50:
    check = false;
    if(arr.length == 0){arr.push("2300"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "2300"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("2300"); colorChange(j-4);}}
      break;
    case 51:
    check = false;
    if(arr.length == 0){arr.push("2330"); colorChange(j-4);}else{
      for(let k=0; k<arr.length; k++)
      {
        if(arr[k] == "2330"){check =true; arr.splice(k, 1); colorReset(j-4);}
      }
      if(!check){arr.push("2330"); colorChange(j-4);}}
      break;
    default:
    break;
  }

  console.log(arr);
}

/**
 * Defines behavior of various document elements with event handlers and appropriate function calls. Calls "getEventsFromDB" to populate the events array when dicument is ready.
 */
$(document).ready(function(){

  getEventsFromDB('php/getEventsFromDB.php', /**
   * Prints the info obtained from the path file to the console for debugging
   */function printResults()
  {
    console.log(events_arr.length); //DEBUGGING
    console.log(events_arr[0]); //DEBUGGING
    console.log(events_arr[1]); //DEBUGGING
    console.log(events_arr[1][1]);
    console.log(events_arr.length);
  });

  $("#organizer_error").hide();
  $("#date_select").hide();
  $("#date_form").hide();
  $("#name_form").hide();
  $("#form_replace").hide();
  $("#event_list").empty();
  $("#event_info").empty();
  $("#event_time").hide();

  $("#date_event").click(function()
  {
    $("#name_form").hide();
    $("#form_replace").hide();
    $("#time_switch").empty();
    $("#event_list").empty();
    $("#event_list").hide();
    $("#date_form").toggle();
    $("#event_info").empty();
    $("#user_table_12").empty();
    $("#user_table_24").empty();
    $("#time_submit").empty();
    $("#event_time").hide();
  });

  $("#all_event").click(function()
  {
    $("#date_form").hide();
    $("#form_replace").hide();
    $("#time_switch").empty();
    $("#event_list").empty();
    $("#event_list").hide();
    $("#name_form").toggle();
    $("#event_list").empty();
    $("#event_info").empty();
    $("#user_table_12").empty();
    $("#user_table_24").empty();
    $("#time_submit").empty();
    $("#event_time").hide();
  });

  $("#name_submit").click(function(){showAllEvents(document.getElementById("name_form"));});

  $("#date_submit").click(
    function()
    {
      $("#event_list").empty();
      getData(document.getElementById("date_form"));
    }
  );

  $("#time_select_12").click(
    function()
    {
      $("#user_table_24").hide();
      $("#user_table_12").toggle();
    });

  $("#time_select_24").click(
    function()
    {
      $("#user_table_12").hide();
      $("#user_table_24").toggle();
    });


});
