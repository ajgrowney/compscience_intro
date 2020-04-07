#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include <string>
template <typename T>

class LinkedList{
public:
    //constructor
    LinkedList();
    //larger scale public method that'll begin the recursion process
    void reverseList(std::string filename);
    //preconditions: the linked list has been implemented and has an m_front
    //postconditions: linked list has a new Node<T>* added to the back
    //return: none
    void addBack(T val);
    //preconditions: there is a Node at where we're looking
    //postconditions: none
    //return m_value from the desired Node<T>*
    T getEntry(int pos);

    //preconditions: the linked list is full and ready to reverse
    //postconditions: list is reversed
    //return: none
    void recReverseList(Node<T>* cur);


    //precondiitons: none
    //postconditions: none
    //return: m_length
    int getLength() const;
    //destructor
    ~LinkedList();
private:
    Node<T>* m_front;
    int m_length;

};
#include "linkedlist.hpp"
#endif // LINKEDLIST_H
