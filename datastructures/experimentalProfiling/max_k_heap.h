#ifndef MAX_K_HEAP
#define MAX_K_HEAP
#include <math.h>
#include "HeapInterface.h"
template<typename T>
class MaxKHeap: public HeapInterface<T>{

	// See Implementation for Pre,Post,Return Conditions

public:
	MaxKHeap(int size);
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
#include "max_k_heap.hpp"
#endif
