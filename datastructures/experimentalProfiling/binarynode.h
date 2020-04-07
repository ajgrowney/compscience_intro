#ifndef BINARYNODE_H
#define BINARYNODE_H

template <typename T>
class BinaryNode{
public:
	BinaryNode();
	BinaryNode(T val);
	void setLSTPointer(BinaryNode<T>* new_node);
	void setRSTPointer(BinaryNode<T>* new_node);
	void setValue(T val);
	BinaryNode<T>* getLSTPointer();
	BinaryNode<T>* getRSTPointer();
	T getValue();
private:
	T m_value;
	BinaryNode<T>* m_lst;
	BinaryNode<T>* m_rst;
};

#include "binarynode.hpp"
#endif
