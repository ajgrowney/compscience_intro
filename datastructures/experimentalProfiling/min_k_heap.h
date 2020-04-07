#ifndef MIN_K_HEAP
#define MIN_K_HEAP
#include <math.h>
#include "HeapInterface.h"
template<typename T>
class MinKHeap: public HeapInterface<T>{

	// See Implementation for Pre,Post,Return Conditions

public:
	MinKHeap(int size);
	void insert_bottomup(T val);
	void insert_upheap(T val);
	void buildheap();

	bool isEmpty() const;

	bool deleteMin();

	int findMin();
	int findMax();
	bool deleteMax();

	void levelOrder();
private:
	T m_array[10000000];
	int k;
	int num_elements;
};
#include "min_k_heap.hpp"
#endif
