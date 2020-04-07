#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "bst.h"
#include "min_k_heap.h"
#include "max_k_heap.h"
#include <time.h>
#include <stdlib.h>
class Executive{
public:
	Executive();
	int calcAverage(int myArr[],int arr_size);
	void displayResults();
	void testBuild(int m);
	//void testDelete(int table_size_input);
	void testTreesAndHeaps(int table_size_input);
	void run();
private:
	bool firstTestRan;
	BinarySearchTree<int>* myBST;
	MinKHeap<int>* myMinKHeap;
	MaxKHeap<int>* myMaxKHeap;
	//
	// ----Final Arrays to Place in Performance Tables-----
	//
	int MinKFinalBuild[5];
	int MinKFinalDeleteMin[5];
	int MinKFinalDeleteMax[5];
	int MaxKFinalBuild[5];
	int MaxKFinalDeleteMin[5];
	int MaxKFinalDeleteMax[5];
	int BSTFinalBuild[5];
	int BSTFinalDeleteMin[5];
	int BSTFinalDeleteMax[5];
	int MinK_Build_Trial[5];
	int MaxK_Build_Trial[5];
	int BST_Build_Trial[5];
	int MinK_DeleteMin_Trial[5];
	int MinK_DeleteMax_Trial[5];
	int MaxK_DeleteMin_Trial[5];
	int MaxK_DeleteMax_Trial[5];
	int BST_DeleteMin_Trial[5];
	int BST_DeleteMax_Trial[5];
};
#include "executive.hpp"
#endif
