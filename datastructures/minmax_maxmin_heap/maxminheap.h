#ifndef MAXMINHEAP_H
#define MAXMINHEAP_H
#include <math.h>
#include "HeapInterface.h"
template<typename T>
class MaxMinHeap: public HeapInterface<T>{

	// See Implementation for Pre,Post,Return Conditions

public:
	MaxMinHeap(int size);
	void insert_bottomup(T val);
	void upheap(int index);
	void insert_upheap(T val);
	void buildheap_recursive(int index);
	void buildheap();

	bool isEmpty() const;

	bool deleteMin_help(int index, T holder);
	bool deleteMin();

	int findMin();
	int findMax();
	bool deleteMax_help(int index, T holder);
	bool deleteMax();

	void levelOrder();
	~MaxMinHeap();
private:
	T m_array[500];
	int k;
	int num_elements;
};
#include "maxminheap.hpp"
#endif
