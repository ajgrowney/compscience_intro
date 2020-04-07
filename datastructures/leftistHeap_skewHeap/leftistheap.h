#ifndef LEFTISTHEAP_H
#define LEFTISTHEAP_H
#include <fstream>
#include <iostream>
#include "leftistnode.h"
#include "concatqueue.h"


template <typename T>
class LeftistHeap: public ConcatenatedQueue<T>{
public:
  LeftistHeap();
  bool isEmpty();
  LeftistNode<T>* concat(LeftistNode<T>* h1, LeftistNode<T>* h2);
  void build();
  void insert(T val);
  void deleteMin();
  void preorder_helper(LeftistNode<T>* subtreePtr);
  void preorder();
  void inorder_helper(LeftistNode<T>* subtreePtr);
  void inorder();
  void levelorder_helper(LeftistNode<T>* subtreePtr, int depth);
  void levelorder();
  void destroy_tree(LeftistNode<T>* subtreePtr);
  ~LeftistHeap();
private:
  LeftistNode<T>* m_root;
  DisplayQueue<T>* m_display;
};
#include "leftistheap.hpp"
#endif
