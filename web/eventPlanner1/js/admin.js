
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///File Name: admin.js
///Author: Andrew Growney, Kaiser Mittenburg, Juzer Zarif
///Purpose: Running JavaScript scripts for HTML elements and contains back-end logic
///Last Modified: 09/17/2017
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

{
  /**
   * Array to store information for all events; populated whenever page loads 
   */
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
  
  
  //Call script
  getEventsFromDB('php/getEventsFromDB.php', /**
   * Debugging function that prints event detais to the console
   */function printResults()
      {
            console.log(events_arr); //DEBUGGING
            console.log(events_arr[0]); //DEBUGGING
            console.log(events_arr[1]); //DEBUGGING
      });
}

/** 
 * Array that stores information about the status of every 30-minute time interval. 
 * At every array index: object{active : boolean bit to denote whether that time interval is going to have an event during it or not  
 *                              attendees: Set to organizer's name if the time interval is active, aet to "0" otherwise}
 */
var time_arr = [];
for(let i=0; i<48; i++)
{
    let obj = {active: false, attendees: "0"};
    time_arr.push(obj);
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
 * Defines the logic to be executed when a button for a specific time interval is clicked
 * @param {number} num - Index corresponding to a time interval in "time_arr"
 */
function clickfunc(num)
{
    time_arr[num].active = !time_arr[num].active;

    for(var i=0; i<48;i++){
      if(time_arr[i].active){
        colorChange(i);
      }else{
        colorReset(i);
      }
    }
}

/**
 * Resets the values of the object properties at every index in "time_arr"
 */
function timeReset()
{
    for(let i=0; i<48; i++)
    {
        time_arr[i].active = false;
        time_arr[i].attendees = "0";
    }
}

/**
 * Collects input from form elements and the time table buttons and sends it to the database.
 * @param {object} form - HTML form element that takes user input for Organizer Name, Event Name, Event Date, and Event Times 
 */
function formData(form)
{
    let name = form.admin_name.value;
    let ev_name = form.event_name.value;
    let date = form.event_date.value;
    let timecheck = false;
    for(let i=0; i<48; i++)
    {
        console.log(time_arr[i].active);
        if(time_arr[i].active)
        {
            timecheck = true;
            time_arr[i].attendees = name + ", ";
        }
    }
    if(name=="" || ev_name=="" || date=="" || (timecheck==false))
    {
        alert("All fields are mandatory!");
    }
    else
    {
    /////////////////////////////////////////////////////////////////////
    //Adapted from code found at https://www.w3schools.com/php/php_ajax_database.asp
    // 9/10/2017 15:25

    if (window.XMLHttpRequest)
    {
        // code for IE7+, Firefox, Chrome, Opera, Safari
        xmlhttp=new XMLHttpRequest();
    }
    else
    { // code for IE6, IE5
        xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
    }
    xmlhttp.onreadystatechange=function()
    {
        if (this.readyState==4 && this.status==200)
        {
        document.getElementById("txtHint").innerHTML=this.responseText;
        }
    }
    var PageToSendTo = "php/saveEventToDB.php?";

    var addOns = "";
    for(var i = 0; i < 48; i++)
    {
        let attendees;
        if(time_arr[i].active)
        {
          attendees = "" + time_arr[i].attendees;
        }
        else
        {
            attendees = "0";
        }

        let time = " ";
        switch(i)
        {
          case 0:
            time = "0000";
            break;
          case 1:
            time = "0030";
            break;
          case 2:
            time = "0100";
            break;
          case 3:
            time = "0130";
            break;
          case 4:
            time = "0200";
            break;
          case 5:
            time = "0230";
            break;
          case 6:
            time = "0300";
            break;
          case 7:
            time = "0330";
            break;
          case 8:
            time = "0400";
            break;
          case 9:
            time = "0430";
            break;
          case 10:
            time = "0500";
            break;
          case 11:
            time = "0530";
            break;
          case 12:
            time = "0600";
            break;
          case 13:
            time = "0630";
            break;
          case 14:
            time = "0700";
            break;
          case 15:
            time = "0730";
            break;
          case 16:
            time = "0800";
            break;
          case 17:
            time = "0830";
            break;
          case 18:
            time = "0900";
            break;
          case 19:
            time = "0930";
            break;
          case 20:
            time = "1000";
            break;
          case 21:
            time = "1030";
            break;
          case 22:
            time = "1100";
            break;
          case 23:
            time = "1130";
            break;
          case 24:
            time = "1200";
            break;
          case 25:
            time = "1230";
            break;
          case 26:
            time = "1300";
            break;
          case 27:
            time = "1330";
            break;
          case 28:
            time = "1400";
            break;
          case 29:
            time = "1430";
            break;
          case 30:
            time = "1500";
            break;
          case 31:
            time = "1530";
            break;
          case 32:
            time = "1600";
            break;
          case 33:
            time = "1630";
            break;
          case 34:
            time = "1700";
            break;
          case 35:
            time = "1730";
            break;
          case 36:
            time = "1800";
            break;
          case 37:
            time = "1830";
            break;
          case 38:
            time = "1900";
            break;
          case 39:
            time = "1930";
            break;
          case 40:
            time = "2000";
            break;
          case 41:
            time = "2030";
            break;
          case 42:
            time = "2100";
            break;
          case 43:
            time = "2130";
            break;
          case 44:
            time = "2200";
            break;
          case 45:
            time = "2230";
            break;
          case 46:
            time = "2300";
            break;
          case 47:
            time = "2330";
            break;
          default:
            time = "0";
            break;
        }
        
        addOns += time + "=" + JSON.stringify(attendees) + "&";

    }
    //alert(addOns); //debugging

    var UrlToSend = PageToSendTo + "name=" + JSON.stringify(name) + "&event_name=" + JSON.stringify(ev_name) + "&date=" + JSON.stringify(date) + "&" + addOns;

    //console.log(JSON.stringify(name));
    xmlhttp.open("GET", UrlToSend, false);
    xmlhttp.send();
    //END ADAPTATION
    //////////////////////////////////////////////////////////////////////
    form.reset();
    timeReset();

    //Reset all time colors
    for(var i=0;i<48;i++){
      colorReset(i);
    }
    }
    //Reload page. FORCE RELOAD (do not reload from cache) is true,
    location.reload(true);
}

/**
 * Populates a table with attendee information for every 30-minute interval for a specific event in 12-hour mode
 * @param {number} n - Row number of the event in the database
 */
function makeTable12(n)
{
  $("#review_table_12").html(
    "<center>Event Schedule</center><br>"+
    "<table id='rev_table'>"+
    "<tr>"+
    "<td><p id = '1200am'>12:00am</p></td>"+"<td><p id = '1230am'>12:30am</p></td>"+"<td><p id = '100am'>1:00am</p></td>"+"<td><p id = '130am'>1:30am</p></td>"+"<td><p id = '200am'>2:00am</p></td>"+"<td><p id = '230am'>2:30am</p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '300am'>3:00am</p></td>"+"<td><p id = '330am'>3:30am</p></td>"+"<td><p id = '400am'>4:00am</p></td>"+"<td><p id = '430am'>4:30am</p></td>"+"<td><p id = '500am'>5:00am</p></td>"+"<td><p id = '530am'>5:30am</p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '600am'>6:00am</p></td>"+"<td><p id = '630am'>6:30am</p></td>"+"<td><p id = '700am'>7:00am</p></td>"+"<td><p id = '730am'>7:30am</p></td>"+"<td><p id = '800am'>8:00am</p></td>"+"<td><p id = '830am'>8:30am</p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '900am'>9:00am</p></td>"+"<td><p id = '930am'>9:30am</p></td>"+"<td><p id = '1000am'>10:00am</p></td>"+"<td><p id = '1030am'>10:30am</p></td>"+"<td><p id = '1100am'>11:00am</p></td>"+"<td><p id = '1130am'>11:30am</p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '1200pm'>12:00pm</p></td>"+"<td><p id = '1230pm'>12:30pm</p></td>"+"<td><p id = '100pm'>1:00pm</p></td>"+"<td><p id = '130pm'>1:30pm</p></td>"+"<td><p id = '200pm'>2:00pm</p></td>"+"<td><p id = '230pm'>2:30pm</p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '300pm'>3:00pm</p></td>"+"<td><p id = '330pm'>3:30pm</p></td>"+"<td><p id = '400pm'>4:00pm</p></td>"+"<td><p id = '430pm'>4:30pm</p></td>"+"<td><p id = '500pm'>5:00pm</p></td>"+"<td><p id = '530pm'>5:30pm</p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '600pm'>6:00pm</p></td>"+"<td><p id = '630pm'>6:30pm</p></td>"+"<td><p id = '700pm'>7:00pm</p></td>"+"<td><p id = '730pm'>7:30pm</p></td>"+"<td><p id = '800pm'>8:00pm</p></td>"+"<td><p id = '830pm'>8:30pm</p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '900pm'>9:00pm</p></td>"+"<td><p id = '930pm'>9:30pm</p></td>"+"<td><p id = '1000pm'>10:00pm</p></td>"+"<td><p id = '1030pm'>10:30pm</p></td>"+"<td><p id = '1100pm'>11:00pm</p></td>"+"<td><p id = '1130pm'>11:30pm</p></td>"+
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
        if(att != "0"){att=att.substring(0, att.length-2); $("#1200am").append("<br>Attendees: "+att); $("#1200am").css("background-color","#80C468");}
        break;
      case 5:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1230am").append("<br>Attendees: "+att); $("#1230am").css("background-color","#80C468");}
        break;
      case 6:
        if(att != "0"){att=att.substring(0, att.length-2); $("#100am").append("<br>Attendees: "+att); $("#100am").css("background-color","#80C468");}
        break;
      case 7:
        if(att != "0"){att=att.substring(0, att.length-2); $("#130am").append("<br>Attendees: "+att); $("#130am").css("background-color","#80C468");}
        break;
      case 8:
        if(att != "0"){att=att.substring(0, att.length-2); $("#200am").append("<br>Attendees: "+att); $("#200am").css("background-color","#80C468");}
        break;
      case 9:
        if(att != "0"){att=att.substring(0, att.length-2); $("#230am").append("<br>Attendees: "+att); $("#230am").css("background-color","#80C468");}
        break;
      case 10:
        if(att != "0"){att=att.substring(0, att.length-2); $("#300am").append("<br>Attendees: "+att); $("#300am").css("background-color","#80C468");}
        break;
      case 11:
        if(att != "0"){att=att.substring(0, att.length-2); $("#330am").append("<br>Attendees: "+att); $("#330am").css("background-color","#80C468");}
        break;
      case 12:
        if(att != "0"){att=att.substring(0, att.length-2); $("#400am").append("<br>Attendees: "+att); $("#400am").css("background-color","#80C468");}
        break;
      case 13:
        if(att != "0"){att=att.substring(0, att.length-2); $("#430am").append("<br>Attendees: "+att); $("#430am").css("background-color","#80C468");}
        break;
      case 14:
        if(att != "0"){att=att.substring(0, att.length-2); $("#500am").append("<br>Attendees: "+att); $("#500am").css("background-color","#80C468");}
        break;
      case 15:
        if(att != "0"){att=att.substring(0, att.length-2); $("#530am").append("<br>Attendees: "+att); $("#530am").css("background-color","#80C468");}
        break;
      case 16:
        if(att != "0"){att=att.substring(0, att.length-2); $("#600am").append("<br>Attendees: "+att); $("#600am").css("background-color","#80C468");}
        break;
      case 17:
        if(att != "0"){att=att.substring(0, att.length-2); $("#630am").append("<br>Attendees: "+att); $("#630am").css("background-color","#80C468");}
        break;
      case 18:
        if(att != "0"){att=att.substring(0, att.length-2); $("#700am").append("<br>Attendees: "+att); $("#700am").css("background-color","#80C468");}
        break;
      case 19:
        if(att != "0"){att=att.substring(0, att.length-2); $("#730am").append("<br>Attendees: "+att); $("#730am").css("background-color","#80C468");}
        break;
      case 20:
        if(att != "0"){att=att.substring(0, att.length-2); $("#800am").append("<br>Attendees: "+att); $("#800am").css("background-color","#80C468");}
        break;
      case 21:
        if(att != "0"){att=att.substring(0, att.length-2); $("#830am").append("<br>Attendees: "+att); $("#830am").css("background-color","#80C468");}
        break;
      case 22:
        if(att != "0"){att=att.substring(0, att.length-2); $("#900am").append("<br>Attendees: "+att); $("#900am").css("background-color","#80C468");}
        break;
      case 23:
        if(att != "0"){att=att.substring(0, att.length-2); $("#930am").append("<br>Attendees: "+att); $("#930am").css("background-color","#80C468");}
        break;
      case 24:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1000am").append("<br>Attendees: "+att); $("#1000am").css("background-color","#80C468");}
        break;
      case 25:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1030am").append("<br>Attendees: "+att); $("#1030am").css("background-color","#80C468");}
        break;
      case 26:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1100am").append("<br>Attendees: "+att); $("#1100am").css("background-color","#80C468");}
        break;
      case 27:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1130am").append("<br>Attendees: "+att); $("#1130am").css("background-color","#80C468");}
        break;
      case 28:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1200pm").append("<br>Attendees: "+att); $("#1200pm").css("background-color","#80C468");}
        break;
      case 29:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1230pm").append("<br>Attendees: "+att); $("#1230pm").css("background-color","#80C468");}
        break;
      case 30:
        if(att != "0"){att=att.substring(0, att.length-2); $("#100pm").append("<br>Attendees: "+att); $("#100pm").css("background-color","#80C468");}
        break;
      case 31:
        if(att != "0"){att=att.substring(0, att.length-2); $("#130pm").append("<br>Attendees: "+att); $("#130pm").css("background-color","#80C468");}
        break;
      case 32:
        if(att != "0"){att=att.substring(0, att.length-2); $("#200pm").append("<br>Attendees: "+att); $("#200pm").css("background-color","#80C468");}
        break;
      case 33:
        if(att != "0"){att=att.substring(0, att.length-2); $("#230pm").append("<br>Attendees: "+att); $("#230pm").css("background-color","#80C468");}
        break;
      case 34:
        if(att != "0"){att=att.substring(0, att.length-2); $("#300pm").append("<br>Attendees: "+att); $("#300pm").css("background-color","#80C468");}
        break;
      case 35:
        if(att != "0"){att=att.substring(0, att.length-2); $("#330pm").append("<br>Attendees: "+att); $("#330pm").css("background-color","#80C468");}
        break;
      case 36:
        if(att != "0"){att=att.substring(0, att.length-2); $("#400pm").append("<br>Attendees: "+att); $("#400pm").css("background-color","#80C468");}
        break;
      case 37:
        if(att != "0"){att=att.substring(0, att.length-2); $("#430pm").append("<br>Attendees: "+att); $("#430pm").css("background-color","#80C468");}
        break;
      case 38:
        if(att != "0"){att=att.substring(0, att.length-2); $("#500pm").append("<br>Attendees: "+att); $("#500pm").css("background-color","#80C468");}
        break;
      case 39:
        if(att != "0"){att=att.substring(0, att.length-2); $("#530pm").append("<br>Attendees: "+att); $("#530pm").css("background-color","#80C468");}
        break;
      case 40:
        if(att != "0"){att=att.substring(0, att.length-2); $("#600pm").append("<br>Attendees: "+att); $("#600pm").css("background-color","#80C468");}
        break;
      case 41:
        if(att != "0"){att=att.substring(0, att.length-2); $("#630pm").append("<br>Attendees: "+att); $("#630pm").css("background-color","#80C468");}
        break;
      case 42:
        if(att != "0"){att=att.substring(0, att.length-2); $("#700pm").append("<br>Attendees: "+att); $("#700pm").css("background-color","#80C468");}
        break;
      case 43:
        if(att != "0"){att=att.substring(0, att.length-2); $("#730pm").append("<br>Attendees: "+att); $("#730pm").css("background-color","#80C468");}
        break;
      case 44:
        if(att != "0"){att=att.substring(0, att.length-2); $("#800pm").append("<br>Attendees: "+att); $("#800pm").css("background-color","#80C468");}
        break;
      case 45:
        if(att != "0"){att=att.substring(0, att.length-2); $("#830pm").append("<br>Attendees: "+att); $("#830pm").css("background-color","#80C468");}
        break;
      case 46:
        if(att != "0"){att=att.substring(0, att.length-2); $("#900pm").append("<br>Attendees: "+att); $("#900pm").css("background-color","#80C468");}
        break;
      case 47:
        if(att != "0"){att=att.substring(0, att.length-2); $("#930pm").append("<br>Attendees: "+att); $("#930pm").css("background-color","#80C468");}
        break;
      case 48:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1000pm").append("<br>Attendees: "+att); $("#1000pm").css("background-color","#80C468");}
        break;
      case 49:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1030pm").append("<br>Attendees: "+att); $("#1030pm").css("background-color","#80C468");}
        break;
      case 50:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1100pm").append("<br>Attendees: "+att); $("#1100pm").css("background-color","#80C468");}
        break;
      case 51:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1130pm").append("<br>Attendees: "+att); $("#1130pm").css("background-color","#80C468");}
        break;
      default:
        break;
    }
  }
}

/**
 * Populates a table with attendee information for every 30-minute interval for a specific event in 24-hour mode
 * @param {number} n - Row number of the event in the database 
 */
function makeTable24(n)
{
  $("#review_table_24").html(
    "<center>Event Schedule</center><br>"+
    "<table id='rev_table'>"+
    "<tr>"+
    "<td><p id = '0000'>00:00</p></td>"+"<td><p id = '0030'>00:30</p></td>"+"<td><p id = '100'>1:00</p></td>"+"<td><p id = '130'>1:30</p></td>"+"<td><p id = '200'>2:00</p></td>"+"<td><p id = '230'>2:30</p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '300'>3:00</p></td>"+"<td><p id = '330'>3:30</p></td>"+"<td><p id = '400'>4:00</p></td>"+"<td><p id = '430'>4:30</p></td>"+"<td><p id = '500'>5:00</p></td>"+"<td><p id = '530'>5:30</p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '600'>6:00</p></td>"+"<td><p id = '630'>6:30</p></td>"+"<td><p id = '700'>7:00</p></td>"+"<td><p id = '730'>7:30</p></td>"+"<td><p id = '800'>8:00</p></td>"+"<td><p id = '830'>8:30</p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '900'>9:00</p></td>"+"<td><p id = '930'>9:30</p></td>"+"<td><p id = '1000'>10:00</p></td>"+"<td><p id = '1030'>10:30</p></td>"+"<td><p id = '1100'>11:00</p></td>"+"<td><p id = '1130'>11:30</p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '1200'>12:00</p></td>"+"<td><p id = '1230'>12:30</p></td>"+"<td><p id = '1300'>13:00</p></td>"+"<td><p id = '1330'>13:30</p></td>"+"<td><p id = '1400'>14:00</p></td>"+"<td><p id = '1430'>14:30</p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '1500'>15:00</p></td>"+"<td><p id = '1530'>15:30</p></td>"+"<td><p id = '1600'>16:00</p></td>"+"<td><p id = '1630'>16:30</p></td>"+"<td><p id = '1700'>17:00</p></td>"+"<td><p id = '1730'>17:30</p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '1800'>18:00</p></td>"+"<td><p id = '1830'>18:30</p></td>"+"<td><p id = '1900'>19:00</p></td>"+"<td><p id = '1930'>19:30</p></td>"+"<td><p id = '2000'>20:00</p></td>"+"<td><p id = '2030'>20:30</p></td>"+
    "</tr>"+
    "<tr>"+
    "<td><p id = '2100'>21:00</p></td>"+"<td><p id = '2130'>21:30</p></td>"+"<td><p id = '2200'>22:00</p></td>"+"<td><p id = '2230'>22:30</p></td>"+"<td><p id = '2300'>23:00</p></td>"+"<td><p id = '2330'>23:30</p></td>"+
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
        if(att != "0"){att=att.substring(0, att.length-2); $("#0000").append("<br>Attendees: "+att); $("#0000").css("background-color","#80C468");}
        break;
      case 5:
        if(att != "0"){att=att.substring(0, att.length-2); $("#0030").append("<br>Attendees: "+att); $("#0030").css("background-color","#80C468");}
        break;
      case 6:
        if(att != "0"){att=att.substring(0, att.length-2); $("#100").append("<br>Attendees: "+att); $("#100").css("background-color","#80C468");}
        break;
      case 7:
        if(att != "0"){att=att.substring(0, att.length-2); $("#130").append("<br>Attendees: "+att); $("#130").css("background-color","#80C468");}
        break;
      case 8:
        if(att != "0"){att=att.substring(0, att.length-2); $("#200").append("<br>Attendees: "+att); $("#200").css("background-color","#80C468");}
        break;
      case 9:
        if(att != "0"){att=att.substring(0, att.length-2); $("#230").append("<br>Attendees: "+att); $("#230").css("background-color","#80C468");}
        break;
      case 10:
        if(att != "0"){att=att.substring(0, att.length-2); $("#300").append("<br>Attendees: "+att); $("#300").css("background-color","#80C468");}
        break;
      case 11:
        if(att != "0"){att=att.substring(0, att.length-2); $("#330").append("<br>Attendees: "+att); $("#330").css("background-color","#80C468");}
        break;
      case 12:
        if(att != "0"){att=att.substring(0, att.length-2); $("#400").append("<br>Attendees: "+att); $("#400").css("background-color","#80C468");}
        break;
      case 13:
        if(att != "0"){att=att.substring(0, att.length-2); $("#430").append("<br>Attendees: "+att); $("#430").css("background-color","#80C468");}
        break;
      case 14:
        if(att != "0"){att=att.substring(0, att.length-2); $("#500").append("<br>Attendees: "+att); $("#500").css("background-color","#80C468");}
        break;
      case 15:
        if(att != "0"){att=att.substring(0, att.length-2); $("#530").append("<br>Attendees: "+att); $("#530").css("background-color","#80C468");}
        break;
      case 16:
        if(att != "0"){att=att.substring(0, att.length-2); $("#600").append("<br>Attendees: "+att); $("#600").css("background-color","#80C468");}
        break;
      case 17:
        if(att != "0"){att=att.substring(0, att.length-2); $("#630").append("<br>Attendees: "+att); $("#630").css("background-color","#80C468");}
        break;
      case 18:
        if(att != "0"){att=att.substring(0, att.length-2); $("#700").append("<br>Attendees: "+att); $("#700").css("background-color","#80C468");}
        break;
      case 19:
        if(att != "0"){att=att.substring(0, att.length-2); $("#730").append("<br>Attendees: "+att); $("#730").css("background-color","#80C468");}
        break;
      case 20:
        if(att != "0"){att=att.substring(0, att.length-2); $("#800").append("<br>Attendees: "+att); $("#800").css("background-color","#80C468");}
        break;
      case 21:
        if(att != "0"){att=att.substring(0, att.length-2); $("#830").append("<br>Attendees: "+att); $("#830").css("background-color","#80C468");}
        break;
      case 22:
        if(att != "0"){att=att.substring(0, att.length-2); $("#900").append("<br>Attendees: "+att); $("#900").css("background-color","#80C468");}
        break;
      case 23:
        if(att != "0"){att=att.substring(0, att.length-2); $("#930").append("<br>Attendees: "+att); $("#930").css("background-color","#80C468");}
        break;
      case 24:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1000").append("<br>Attendees: "+att); $("#1000").css("background-color","#80C468");}
        break;
      case 25:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1030").append("<br>Attendees: "+att); $("#1030").css("background-color","#80C468");}
        break;
      case 26:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1100").append("<br>Attendees: "+att); $("#1100").css("background-color","#80C468");}
        break;
      case 27:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1130").append("<br>Attendees: "+att); $("#1130").css("background-color","#80C468");}
        break;
      case 28:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1200").append("<br>Attendees: "+att); $("#1200").css("background-color","#80C468");}
        break;
      case 29:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1230").append("<br>Attendees: "+att); $("#1230").css("background-color","#80C468");}
        break;
      case 30:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1300").append("<br>Attendees: "+att); $("#1300").css("background-color","#80C468");}
        break;
      case 31:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1330").append("<br>Attendees: "+att); $("#1330").css("background-color","#80C468");}
        break;
      case 32:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1400").append("<br>Attendees: "+att); $("#1400").css("background-color","#80C468");}
        break;
      case 33:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1430").append("<br>Attendees: "+att); $("#1430").css("background-color","#80C468");}
        break;
      case 34:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1500").append("<br>Attendees: "+att); $("#1500").css("background-color","#80C468");}
        break;
      case 35:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1530").append("<br>Attendees: "+att); $("#1530").css("background-color","#80C468");}
        break;
      case 36:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1600").append("<br>Attendees: "+att); $("#1600").css("background-color","#80C468");}
        break;
      case 37:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1630").append("<br>Attendees: "+att); $("#1630").css("background-color","#80C468");}
        break;
      case 38:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1700").append("<br>Attendees: "+att); $("#1700").css("background-color","#80C468");}
        break;
      case 39:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1730").append("<br>Attendees: "+att); $("#1730").css("background-color","#80C468");}
        break;
      case 40:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1800").append("<br>Attendees: "+att); $("#1800").css("background-color","#80C468");}
        break;
      case 41:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1830").append("<br>Attendees: "+att); $("#1830").css("background-color","#80C468");}
        break;
      case 42:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1900").append("<br>Attendees: "+att); $("#1900").css("background-color","#80C468");}
        break;
      case 43:
        if(att != "0"){att=att.substring(0, att.length-2); $("#1930").append("<br>Attendees: "+att); $("#1930").css("background-color","#80C468");}
        break;
      case 44:
        if(att != "0"){att=att.substring(0, att.length-2); $("#2000").append("<br>Attendees: "+att); $("#2000").css("background-color","#80C468");}
        break;
      case 45:
        if(att != "0"){att=att.substring(0, att.length-2); $("#2030").append("<br>Attendees: "+att); $("#2030").css("background-color","#80C468");}
        break;
      case 46:
        if(att != "0"){att=att.substring(0, att.length-2); $("#2100").append("<br>Attendees: "+att); $("#2100").css("background-color","#80C468");}
        break;
      case 47:
        if(att != "0"){att=att.substring(0, att.length-2); $("#2130").append("<br>Attendees: "+att); $("#2130").css("background-color","#80C468");}
        break;
      case 48:
        if(att != "0"){att=att.substring(0, att.length-2); $("#2200").append("<br>Attendees: "+att); $("#2200").css("background-color","#80C468");}
        break;
      case 49:
        if(att != "0"){att=att.substring(0, att.length-2); $("#2230").append("<br>Attendees: "+att); $("#2230").css("background-color","#80C468");}
        break;
      case 50:
        if(att != "0"){att=att.substring(0, att.length-2); $("#2300").append("<br>Attendees: "+att); $("#2300").css("background-color","#80C468");}
        break;
      case 51:
        if(att != "0"){att=att.substring(0, att.length-2); $("#2330").append("<br>Attendees: "+att); $("#2330").css("background-color","#80C468");}
        break;
      default:
        break;
    }
  }
}

/**
 * Locates the given event and organizer combo in the database (displays appropriate error message in case of failure), and displays event information
 * @param {object} form - HTML form element that takes input for Organizer Name, and Event Name 
 */
function getData(form)
{
  let name = form.review_admin_name.value;
  let ev_name = form.review_event_name.value;
  let ev_date = "";
  let check = false;
  let row_num = 0;
  if(name=="" || ev_name=="")
  {
    form.reset();
    alert("All fields are mandatory!");
  }
  else
  {
    for(let i=0; i<events_arr.length; i++)
    {
      if(name == events_arr[i][1] && ev_name == events_arr[i][2])
      {
        row_num = i;
        check = true;
      }
    }
    if(!check)
    {
      form.reset();
      $("#event_review").empty();
      $("#review_table_12").empty();
      $("#review_table_24").empty();
      alert("Could not find event and/or name. Please verify input is valid");
    }
    else
    {
      form.reset();
      ev_date = events_arr[row_num][3];
      $("#event_review").append("Event: "+ev_name+"<br><br>");
      $("#event_review").append("Organizer: "+name+"<br><br>");
      $("#event_review").append("Date: "+ev_date);
      $("#12_review").show();
      $("#24_review").show();
      makeTable12(row_num);
      makeTable24(row_num);
      $("#review_table_24").hide();
    }
  }
}

/** Defines behavior of various document elements with event handlers and appropriate function calls. Creates the 30-minute interval buttons for selecting event time. */
$(document).ready(function()
{
    $("#event_form").hide();
    $("#review").hide();
    $("#12_review").hide();
    $("#24_review").hide();
    $("#create_event").click(
        function()
        {
            document.getElementById("event_form").reset();
            timeReset();
            $("#review").hide();
            $("#event_review").empty();
            $("#12_review").hide();
            $("#24_review").hide();
            $("#review_table_12").empty();
            $("#review_table_24").empty();
            $("#event_time_12").hide();
            $("#event_time_24").hide();
            $("#event_form").toggle();
        });


    $("#event_time_12").hide();
    $("#event_time_24").hide();
    $("#time_select_12").click(
        function()
        {
            timeReset();
            $("#event_time_12").empty();
            $("#event_time_24").empty();
            $("#event_time_24").hide();
            $("#event_time_12").html
            (
                "<table>"+
                "<tr>"+
                "<td><button class='time_button' type='button' id='am1200' onclick = 'clickfunc(0)'>12:00am</button></td>"+
                "<td><button class='time_button' type='button' id='am1230' onclick = 'clickfunc(1)'>12:30am</button></td>"+
                "<td><button class='time_button' type='button' id='am100' onclick = 'clickfunc(2)'>1:00am</button></td>"+
                "<td><button class='time_button' type='button' id='am130' onclick = 'clickfunc(3)'>1:30am</button></td>"+
                "<td><button class='time_button' type='button' id='am200' onclick = 'clickfunc(4)'>2:00am</button></td>"+
                "<td><button class='time_button' type='button' id='am230' onclick = 'clickfunc(5)'>2:30am</button></td>"+
                "</tr><tr>"+
                "<td><button class='time_button' type='button' id='am300' onclick = 'clickfunc(6)'>3:00am</button></td>"+
                "<td><button class='time_button' type='button' id='am330' onclick = 'clickfunc(7)'>3:30am</button></td>"+
                "<td><button class='time_button' type='button' id='am400' onclick = 'clickfunc(8)'>4:00am</button></td>"+
                "<td><button class='time_button' type='button' id='am430' onclick = 'clickfunc(9)'>4:30am</button></td>"+
                "<td><button class='time_button' type='button' id='am500' onclick = 'clickfunc(10)'>5:00am</button></td>"+
                "<td><button class='time_button' type='button' id='am530' onclick = 'clickfunc(11)'>5:30am</button></td>"+
                "</tr><tr>"+
                "<td><button class='time_button' type='button' id='am600' onclick = 'clickfunc(12)'>6:00am</button></td>"+
                "<td><button class='time_button' type='button' id='am630' onclick = 'clickfunc(13)'>6:30am</button></td>"+
                "<td><button class='time_button' type='button' id='am700' onclick = 'clickfunc(14)'>7:00am</button></td>"+
                "<td><button class='time_button' type='button' id='am730' onclick = 'clickfunc(15)'>7:30am</button></td>"+
                "<td><button class='time_button' type='button' id='am800' onclick = 'clickfunc(16)'>8:00am</button></td>"+
                "<td><button class='time_button' type='button' id='am830' onclick = 'clickfunc(17)'>8:30am</button></td>"+
                "</tr><tr>"+
                "<td><button class='time_button' type='button' id='am900' onclick = 'clickfunc(18)'>9:00am</button></td>"+
                "<td><button class='time_button' type='button' id='am930' onclick = 'clickfunc(19)'>9:30am</button></td>"+
                "<td><button class='time_button' type='button' id='am1000' onclick = 'clickfunc(20)'>10:00am</button></td>"+
                "<td><button class='time_button' type='button' id='am1030' onclick = 'clickfunc(21)'>10:30am</button></td>"+
                "<td><button class='time_button' type='button' id='am1100' onclick = 'clickfunc(22)'>11:00am</button></td>"+
                "<td><button class='time_button' type='button' id='am1130' onclick = 'clickfunc(23)'>11:30am</button></td>"+
                "</tr><tr>"+
                "<td><button class='time_button' type='button' id='pm1200' onclick = 'clickfunc(24)'>12:00pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm1230' onclick = 'clickfunc(25)'>12:30pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm100' onclick = 'clickfunc(26)'>1:00pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm130' onclick = 'clickfunc(27)'>1:30pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm200' onclick = 'clickfunc(28)'>2:00pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm230' onclick = 'clickfunc(29)'>2:30pm</button></td>"+
                "</tr><tr>"+
                "<td><button class='time_button' type='button' id='pm300' onclick = 'clickfunc(30)'>3:00pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm330' onclick = 'clickfunc(31)'>3:30pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm400' onclick = 'clickfunc(32)'>4:00pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm430' onclick = 'clickfunc(33)'>4:30pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm500' onclick = 'clickfunc(34)'>5:00pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm530' onclick = 'clickfunc(35)'>5:30pm</button></td>"+
                "</tr><tr>"+
                "<td><button class='time_button' type='button' id='pm600' onclick = 'clickfunc(36)'>6:00pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm630' onclick = 'clickfunc(37)'>6:30pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm700' onclick = 'clickfunc(38)'>7:00pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm730' onclick = 'clickfunc(39)'>7:30pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm800' onclick = 'clickfunc(40)'>8:00pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm830' onclick = 'clickfunc(41)'>8:30pm</button></td>"+
                "</tr><tr>"+
                "<td><button class='time_button' type='button' id='pm900' onclick = 'clickfunc(42)'>9:00pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm930' onclick = 'clickfunc(43)'>9:30pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm1000' onclick = 'clickfunc(44)'>10:00pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm1030' onclick = 'clickfunc(45)'>10:30pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm1100' onclick = 'clickfunc(46)'>11:00pm</button></td>"+
                "<td><button class='time_button' type='button' id='pm1130' onclick = 'clickfunc(47)'>11:30pm</button></td>"+
                "</tr></table>"

            );
            $('#event_time_12').toggle();
        });


    $("#time_select_24").click(
        function()
        {
            timeReset();
            $("#event_time_12").empty();
            $("#event_time_12").hide();
            $("#event_time_24").empty();
            $("#event_time_24").html
            (
                "<table>"+
                "<tr>"+
                "<td><button class='time_button' type='button' id='t0000' onclick = 'clickfunc(0)'>00:00</button></td>"+
                "<td><button class='time_button' type='button' id='t0030' onclick = 'clickfunc(1)'>00:30</button></td>"+
                "<td><button class='time_button' type='button' id='t100' onclick = 'clickfunc(2)'>1:00</button></td>"+
                "<td><button class='time_button' type='button' id='t130' onclick = 'clickfunc(3)'>1:30</button></td>"+
                "<td><button class='time_button' type='button' id='t200' onclick = 'clickfunc(4)'>2:00</button></td>"+
                "<td><button class='time_button' type='button' id='t230' onclick = 'clickfunc(5)'>2:30</button></td>"+
                "</tr><tr>"+
                "<td><button class='time_button' type='button' id='t300' onclick = 'clickfunc(6)'>3:00</button></td>"+
                "<td><button class='time_button' type='button' id='t330' onclick = 'clickfunc(7)'>3:30</button></td>"+
                "<td><button class='time_button' type='button' id='t400' onclick = 'clickfunc(8)'>4:00</button></td>"+
                "<td><button class='time_button' type='button' id='t430' onclick = 'clickfunc(9)'>4:30</button></td>"+
                "<td><button class='time_button' type='button' id='t500' onclick = 'clickfunc(10)'>5:00</button></td>"+
                "<td><button class='time_button' type='button' id='t530' onclick = 'clickfunc(11)'>5:30</button></td>"+
                "</tr><tr>"+
                "<td><button class='time_button' type='button' id='t600' onclick = 'clickfunc(12)'>6:00</button></td>"+
                "<td><button class='time_button' type='button' id='t630' onclick = 'clickfunc(13)'>6:30</button></td>"+
                "<td><button class='time_button' type='button' id='t700' onclick = 'clickfunc(14)'>7:00</button></td>"+
                "<td><button class='time_button' type='button' id='t730' onclick = 'clickfunc(15)'>7:30</button></td>"+
                "<td><button class='time_button' type='button' id='t800' onclick = 'clickfunc(16)'>8:00</button></td>"+
                "<td><button class='time_button' type='button' id='t830' onclick = 'clickfunc(17)'>8:30</button></td>"+
                "</tr><tr>"+
                "<td><button class='time_button' type='button' id='t900' onclick = 'clickfunc(18)'>9:00</button></td>"+
                "<td><button class='time_button' type='button' id='t930' onclick = 'clickfunc(19)'>9:30</button></td>"+
                "<td><button class='time_button' type='button' id='t1000' onclick = 'clickfunc(20)'>10:00</button></td>"+
                "<td><button class='time_button' type='button' id='t1030' onclick = 'clickfunc(21)'>10:30</button></td>"+
                "<td><button class='time_button' type='button' id='t1100' onclick = 'clickfunc(22)'>11:00</button></td>"+
                "<td><button class='time_button' type='button' id='t1130' onclick = 'clickfunc(23)'>11:30</button></td>"+
                "</tr><tr>"+
                "<td><button class='time_button' type='button' id='t1200' onclick = 'clickfunc(24)'>12:00</button></td>"+
                "<td><button class='time_button' type='button' id='t1230' onclick = 'clickfunc(25)'>12:30</button></td>"+
                "<td><button class='time_button' type='button' id='t1300' onclick = 'clickfunc(26)'>13:00</button></td>"+
                "<td><button class='time_button' type='button' id='t1330' onclick = 'clickfunc(27)'>13:30</button></td>"+
                "<td><button class='time_button' type='button' id='t1400' onclick = 'clickfunc(28)'>14:00</button></td>"+
                "<td><button class='time_button' type='button' id='t1430' onclick = 'clickfunc(29)'>14:30</button></td>"+
                "</tr><tr>"+
                "<td><button class='time_button' type='button' id='t1500' onclick = 'clickfunc(30)'>15:00</button></td>"+
                "<td><button class='time_button' type='button' id='t1530' onclick = 'clickfunc(31)'>15:30</button></td>"+
                "<td><button class='time_button' type='button' id='t1600' onclick = 'clickfunc(32)'>16:00</button></td>"+
                "<td><button class='time_button' type='button' id='t1630' onclick = 'clickfunc(33)'>16:30</button></td>"+
                "<td><button class='time_button' type='button' id='t1700' onclick = 'clickfunc(34)'>17:00</button></td>"+
                "<td><button class='time_button' type='button' id='t1730' onclick = 'clickfunc(35)'>17:30</button></td>"+
                "</tr><tr>"+
                "<td><button class='time_button' type='button' id='t1800' onclick = 'clickfunc(36)'>18:00</button></td>"+
                "<td><button class='time_button' type='button' id='t1830' onclick = 'clickfunc(37)'>18:30</button></td>"+
                "<td><button class='time_button' type='button' id='t1900' onclick = 'clickfunc(38)'>19:00</button></td>"+
                "<td><button class='time_button' type='button' id='t1930' onclick = 'clickfunc(39)'>19:30</button></td>"+
                "<td><button class='time_button' type='button' id='t2000' onclick = 'clickfunc(40)'>20:00</button></td>"+
                "<td><button class='time_button' type='button' id='t2030' onclick = 'clickfunc(41)'>20:30</button></td>"+
                "</tr><tr>"+
                "<td><button class='time_button' type='button' id='t2100' onclick = 'clickfunc(42)'>21:00</button></td>"+
                "<td><button class='time_button' type='button' id='t2130' onclick = 'clickfunc(43)'>21:30</button></td>"+
                "<td><button class='time_button' type='button' id='t2200' onclick = 'clickfunc(44)'>22:00</button></td>"+
                "<td><button class='time_button' type='button' id='t2230' onclick = 'clickfunc(45)'>22:30</button></td>"+
                "<td><button class='time_button' type='button' id='t2300' onclick = 'clickfunc(46)'>23:00</button></td>"+
                "<td><button class='time_button' type='button' id='t2330' onclick = 'clickfunc(47)'>23:30</button></td>"+
                "</tr></table>"
            );
            $("#event_time_24").toggle();

        });

    $("#submit").click(
        function()
        {
            formData(document.getElementById("event_form"));
        });

    $("#review_event").click(
        function()
        {
            $("#event_review").empty();
            $("#review_table_12").empty();
            $("#review_table_24").empty();
            $("#12_review").hide();
            $("#24_review").hide();
            $("#event_form").hide();
            $("#review").toggle();
        }
    );

    $("#review_submit").click(
        function()
        {
          $("#event_review").empty();
          $("#12_review").hide();
          $("#24_review").hide();
          $("#review_table_12").empty();
          $("#review_table_24").empty();
          getData(document.getElementById("review"));
        }
    );

    $("#12_review").click(
      function()
      {
        $("#review_table_24").hide();
        $("#review_table_12").toggle();
      }
    );

    $("#24_review").click(
      function()
      {
        $("#review_table_12").hide();
        $("#review_table_24").toggle();
      }
    )

});
