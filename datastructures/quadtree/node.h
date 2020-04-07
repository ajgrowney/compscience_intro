#ifndef NODE_H
#define NODE_H
template <typename T>

class Node{
public:
    Node();
    //preconditions: there is a node to get the value from
    //postconditions: none
    //return: m_value
    T getValue();
    //preconditions: there's a node to get the next node pointer from
    //postconditions: none
    //return: m_next
    Node<T>* getNext();
    //preconditions: it is passed a Node<T>* to set the value to
    //postconditions: the node now has m_next pointing to something
    //return: none
    void setNext(Node<T>* nxt);
    //preconditions: it has been passed a valid value that m_value can be set to
    //postconditions: m_value now takes the value val
    //return:none
    void setValue(T val);
private:
    T m_value;
    Node<T>* m_next;
  };
#include "node.hpp"
#endif // NODE_H
