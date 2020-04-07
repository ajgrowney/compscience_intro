/**
*	@author
*	@date
*	@file main.cpp
*	@brief driver for LinkedList demo
*/
#include <iostream>
#include "LinkedListOfInts.h"
#include "TestSuite.h"

int main(int argc, char** argv)
{
	//Example of declaring a LinkedListOfInts
	LinkedListOfInts testableList;

	//You won't do all the tests in main; that's what your Test class will be for
	//Example:
	TestSuite myTester(testableList);
	myTester.runTests();

	std::cout << "\n\nRunning...\nAnd we're done.\nGoodbye.\n";

	return (0);

}
