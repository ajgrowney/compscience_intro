#ifndef LINKEDLIST
#define LINKEDLIST

#include "node.h"
#include<iostream>
#include<vector>

/**
 *	Templated linkedList class. This defines all of the linkedList private member variables and public linkedList methods.
 *	@author	Giovanni Artavia
 *	@author Brandon Lammey
 *	@author	Dylan Herrig
 *	@author James Glass
 */
template <typename T>
class linkedList
{
	private:

		/**
		 *	Private member variable. Points to the front of a linkedList.
		 */
		node<T>* m_front;

		/**
		 *	Private member variable. Holds the current size of a linkedList.
		 */
		int m_size;

	public:

		/**
		 *	Constructor for the linkedList class.
		 */
		linkedList();

		/**
		 *	Destructor for the linkedList class.
		 */
		~linkedList();

		/**
		 *	Public method that takes in no arguments and returns a bool.
		 *	@return true if the list is empty, false otherwise.
		 */
		bool isEmpty() const;

		/**
		 *	Public method that takes no arguments and returns an int.
		 *	@return size of the linkedList.
		 */
		int size() const;

		/**
		 *	Public method that takes one argument of type T and returns a bool.
		 *	Details: Searches linkedList for value of type T.
		 *	@param value the first argument.
		 *	@return true if the value exists in any node in the linkedList, false otherwise.
		 */
		bool search(T value) const;

		/**
		 *	Public method that takes no arguments and does not return.
		 *	Details: Prints linkedList to console. If empty, prints a message stating so.
		 */
		void printList() const;

		/**
		 *	Public method that takes one argument of type T and does not return.
		 *	Details: Adds node containing value of type T to the back of the linkedList. If empty, adds to the front. Increments size.
		 *	@param value the first argument.
		 */
		void addBack(T value);

		/**
		 *	Public method that takes one argument of type T and does not return.
		 *	Details: Adds node containing value of type T to the front of the linkedList. Increments size.
		 *	@param value the first argument.
		 */
		void addFront(T value);

		/**
		 *	Public method that takes in no arguments and returns a bool.
		 *	Details: Removes a node from the back of the linkedList. Decrements size.
		 *	@return true if the removal is successful, false otherwise.
		 */
		bool removeBack();

		/**
		 *	Public method that takes in no arguments and returns a bool.
		 *	Details: Removes a node from the front of the linkedList. Decrements size.
		 *	@return true if the removal is successful, false otherwise.
		 */
		bool removeFront();

		/**
		 *	Public method that takes in no arguments and does not return.
		 *	Details: Sorts the linkedList based on date using a bubble sort.
		 */
		void sortList();

		/**
		 *	Public method that takes in two arguments and returns a bool.
		 *	Details: Compares dates of two adjacent nodes and determines which is more recent.
		 *	@param value0 is the first argument.
		 *	@param value1 is the second argument.
		 *	@return true if value0 is less than value1, false otherwise.
		 */
		bool compareDates(T value0, T value1);

		/**
		 *	Public method that takes in no arguments and returns a vector of type T.
		 *	Details: Creates new vector. Copies contents of linkedList into new vecotr.
		 *	@return a standard vector with the contents of the linkedList inside.
		 */
		std::vector<T> toVector() const;

		/**
		 *	Public method that takes in two arguments and returns a bool.
		 *	Details: Adds node containing value of type T to a given spot in the linkedList. Increments size.
		 *	@param position is the first argument.
		 *	@param value is the second argument.
		 *	@return true if value is inserted succesfully at correct position, false otherwise.
		 */
		bool insert(int position, T value);

		/**
		 *	Public method that takes in one argument and returns a value of type T.
		 *	Details: Grabs value of type T from given position in the linkedList.
		 *	@param position is the first argument.
		 *	@return value from position in the linkedList.
		 */
		T getEntry(int position) const;
};

#include "linkedList.hpp"

#endif
