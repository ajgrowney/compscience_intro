#ifndef BST_H
#define BST_H
#include "binarynode.h"

template<typename T>
class BinarySearchTree{

public:
	BinarySearchTree();
	BinaryNode<T>* getRootPtr();
	void setRootPtr(BinaryNode<T>* newRoot);
	bool isEmpty() const;
	bool insert(T val);
	bool insertRec(T val, BinaryNode<T>* subtreePtr);
	BinaryNode<T>* removeNode(T val, BinaryNode<T>* tmp);
	BinaryNode<T>* removeMin(BinaryNode<T>* traverseNode);
	BinaryNode<T>* removeMax(BinaryNode<T>* traverseNode);
	BinaryNode<T>* findMin(BinaryNode<T>* traverseNode);
	BinaryNode<T>* findMax(BinaryNode<T>* traverseNode);
	void PreOrderTraverse(BinaryNode<T>* traverseNode);
	void InOrderTraverse(BinaryNode<T>* traverseNode);
	void PostOrderTraverse(BinaryNode<T>* traverseNode);
	void PostOrderDeletion(BinaryNode<T>* traverseNode);
	~BinarySearchTree();

private:
	BinaryNode<T>* m_root;
	int m_node_count;

};

#include "bst.hpp"
#endif
