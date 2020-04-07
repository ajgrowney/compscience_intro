#ifndef SKEWHEAP_H
#define SKEWHEAP_H
#include <fstream>
#include <iostream>
#include "concatqueue.h"
#include "skewnode.h"
#include "displayqueue.h"


template <typename T>
class SkewHeap: public ConcatenatedQueue<T>{
public:
  SkewHeap();
  bool isEmpty();
  SkewNode<T>* concat(SkewNode<T>* h1, SkewNode<T>* h2);
  void build();
  void insert(T val);
  void deleteMin();
  void preorder_helper(SkewNode<T>* subtreePtr);
  void preorder();
  void inorder_helper(SkewNode<T>* subtreePtr);
  void inorder();
  void levelorder_helper(SkewNode<T>* subtreePtr, int depth);
  void levelorder();
  void destroy_tree(SkewNode<T>* subtreePtr);
  ~SkewHeap();
private:
  SkewNode<T>* m_root;
  DisplayQueue<T>* m_display;
};
#include "skewheap.hpp"
#endif
