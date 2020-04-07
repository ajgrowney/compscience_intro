date::date()
{
  year = "";
  month = "";
  day = "";
  time = "";
  event = "";
  attendance = "";
  tasks = "";
  initial_year = 0;
  initial_month = 0;
  initial_day = 0;
}

/*bool operator == (const date& date1, const date& date2)
{
  return(year == year && month == month && day == day)
}*/

void date::setYear(std::string y)
{
  year = y;
}

std::string date::getYear()
{
  return year;
}

void date::setMonth(std::string m)
{
  month = m;
}

std::string date::getMonth()
{
  return month;
}

void date::setDay(std::string d)
{
  day = d;
}

std::string date::getDay()
{
  return day;
}

void date::setTime(std::string t)
{
  time = t;
}

std::string date::getTime()
{
  return time;
}

void date::setEvent(std::string e)
{
  event = e;
}

std::string date::getEvent()
{
  return event;
}

void date::setAttendance(std::string a)
{
  attendance = a;
}

std::string date::getAttendance()
{
  return attendance;
}
