#ifndef NODE
#define NODE

/**
 *	Node class. This defines all of the node class' private member variables and public methods.
 *	@author	Giovanni Artavia
 *	@author Brandon Lammey
 *	@author	Dylan Herrig
 *	@author James Glass
 */

template <typename T>
class node
{
	private:

		 /**
		  *	Private member variable. Value in the node.
		 	*/
		 T m_value;

		 /**
 		 	*	Private member variable. Pointer to the next node in the linkedList.
 		 	*/
		 node<T>* m_next;	//pointer to another node

	public:

		 /**
		 	*	Constructor for the node class. Includes a value and a pointer to the next node.
		 	*/
		 node(T value);

		 /**
	 	 	*	Public method that takes one argument of type T and does not return.
	 	 	*	Details: Sets the node's value.
	 	 	*	@param value the first argument.
	 	 	*/
		 void setValue(T value);

		 /**
		 	*	Public method that takes one argument of type node pointer and does not return.
	 	 	*	Details: Sets a pointer on the next node in the linkedList.
	 	 	*	@param next the first argument.
	 	 	*/
		 void setNext(node<T>* next);

		 /**
			*	Public method that takes no arguments and returns a value of type T.
			*	@returns value held in the node.
			*/
		 T getValue() const;

		 /**
 		 	*	Public method that takes no arguments and returns a node pointer.
 		 	*	@returns the next node in the linkedList.
 		 	*/
		 node<T>* getNext() const;
};

#include "node.hpp"

#endif
