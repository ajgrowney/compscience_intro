#ifndef EXEC_H
#define EXEC_H

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <math.h>

#include "date.h"
#include "linkedList.h"

/**
*	Executive class. This defines all of the executive class' private member variables and public methods.
*	@author	Giovanni Artavia
*	@author Brandon Lammey
*	@author	Dylan Herrig
*	@author James Glass
*/
class exec
{
private:

public:
	/**
	*	Constructor for the exec class.
	*/
	exec();
	/**
	*	Destructor for the exec class.
	*/
	~exec();

	/**
	* Public method that returns a vector of times for that event.
	* Details: Creates a vector of the half hour time slots for that event
	* @param none
	* @return vector of event times
	*/
	std::vector<std::vector<std::string>> getTimes();

	/**
	* Public method that takes as argument the event name from the output file, and returns a vector of times for that event.
	* Details: Creates a vector of the half hour time slots for that event
	* @param std::string event_name: The entire time list as formatted in the output file. example: time1 time2 time3....
	* @return vector of event times
	*/
	std::vector<std::string> getTimeOfSingleEvent(std::string event_name);

	/**
	* Public method that takes as argument the task list section from the output file, and returns a vector of tasks.
	* Details: Creates a vector of tasks that haven't already been signed up for by other users
	* @param std::string event_name: The entire task list as formatted in the output file. example: Task1_Name/Task1_User;Tas2_Name/Task2_User;Task3...
	* @return vector of undone tasks
	*/
	std::string getTasksForSingleEvent(std::string event_name, std::string year, std::string month, std::string day);

	/**
	* Public method that takes as argument the task list section from the output file, and returns a vector of tasks.
	* Details: Creates a vector of tasks that haven't already been signed up for by other users
	* @param std::string event_name: The entire task list as formatted in the output file. example: Task1_Name/Task1_User;Tas2_Name/Task2_User;Task3...
	* @return vector of undone tasks
	*/
	std::vector<std::string> generateTaskList(std::string event_tasks);

	/**
	*	Public method that takes in no arguments and does not return.
	* 	Grants user to use admin options.
	* 	Details: Able to create events (creates date object and prints to text file) and preview the current list of events.
	*	@param ultimateEventCheck is the first parameter.
	*	@return false if the file has been created, true otherwise.
	*/
	bool admin(bool ultimateEventCheck);

	/**
	*	Public method that takes in no arguments and does not return.
	* 	Grants user to use user options.
	* 	Details: Able preview the current list of events and then select which event they'd like to attend (Updates text file).
	*/

	void user();

	/**
	*	Public method that takes in one argument as a bool and does not return.
	* 	Details: Creates linked list, accesses text file, creates date objects, and places date objects into sorted linkedList. Prints linkedList in readable form to terminal (uses time parameter to determine 12/24 hr clock).
	* @param takes in time
	*/
	void print(bool time);

	/**
	*	Public method that takes in one argument as an int and returns a string.
	* 	Details: Converts 24hour to 12hour format and formats text (00:00 with AM or PM) for easy readablility.
	*	@param num is the first parameter.
	*	@return formatted string.
	*/
	std::string make12Hr(int num);

	/**
	*	Public method that takes in one argument as an int and returns a string.
	* 	Details: Formats 24hour int into a readable string (00:00).
	*	@param num is the first parameter.
	*	@return formatted string.
	*/
	std::string format24Hr(int num);

	/**
	*	Public method that takes in no arguments and does not return.
	* 	Details: Runs the program and calls to admin or user based on user input.
	*/
	void run();

	/**
	*	Public method that takes in no arguments and does not return.
	* 	Details: Used for testing linkedList sort and early printing.
	*/
	//void test();

	/**
	*	Public method that takes in one argument as a string and returns a bool.
	* 	Details: Searches the .txt file and updates attendence.
	* 	@param eventNameCheck is the first parameter.
	*	@return true if the event was found in the list, false otherwise.
	*/

	/**
	*	Public method that takes in the eventNameCheck, the user's name, the vector of times, the year, the month, and the day and updates the event with input from the user.
	* 	Details: Searches the .txt file for the event then updates it based on input from the user.
	* 	@param eventNameCheck is the first parameter.
	*	@return true if the event was found in the list, false otherwise.
	*/
	bool updateEvent(std::string eventNameCheck, std::string userName, std::vector<std::vector<std::string>> times, std::string year, std::string month, std::string day);


	/**
	*	Public method that takes in one argument as a string and returns a bool.
	* 	Details: Searches the .txt file for the event.
	* 	@param eventNameCheck is the first parameter.
	*	@return true if the event was found in the list, false otherwise.
	*/
	void userChooseHours(std::vector<std::vector<std::string>> times);

	/**
	*	Public method that takes in one argument as a string and returns a bool.
	* 	Details: Searches the .txt file for the event.
	* 	@param eventNameCheck is the first parameter.
	*	@return true if the event was found in the list, false otherwise.
	*/

	/**
	*	Public method that takes in two argument and returns a bool.
	* 	Details: Checks to see if given time is valid.
	* 	@param time is the first parameter.
	*	@param len is the second parameter.
	*	@return true if time is valid, false otherwise.
	*/
	bool eventCheck(std::string eventNameCheck);


	/**
	*	Public method that takes in two argument and returns a bool.
	* 	Details: Checks to see if given time is valid. timeMode is true if in 24 hour mode, false is 12 hour.
	* 	@param time is the first parameter.
	*	@param len is the second parameter.
	*	@param timeMode is the third parameter.
	*	@return true if time is valid, false otherwise.
	*/
	bool timeCheck (int time, int len);


	/**
	* Public method that takes in the time, the length, and the time mode (12 hour or 24 hour as a bool) and returns true if the user inputs an invalid time
	* Details: comfirms that the user enters a valid time in.
	* @param len makes sure the time is 3 or 4 digits long. timeMode determines whether it is 12 or 24 hour mode. Time is the time.
	* @return true if the user inputs something invalid, false otherwise
	*/
	bool timeCheck (int time, int len, bool timeMode);

};

#include "exec.hpp"

#endif
