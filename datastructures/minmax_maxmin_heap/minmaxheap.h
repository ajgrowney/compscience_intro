#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H
#include <math.h>
#include "HeapInterface.h"
template<typename T>
class MinMaxHeap: public HeapInterface<T>{

	// See Implementation for Pre,Post,Return Conditions

public:
	MinMaxHeap(int size);
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
	~MinMaxHeap();
private:
	T m_array[500];
	int k;
	int num_elements;
};
#include "minmaxheap.hpp"
#endif
