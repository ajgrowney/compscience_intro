#ifndef DISPLAYNODE_H
#define DISPLAYNODE_H
#include "displaynode.h"
#include "concatnode.h"

template <typename T>
class DisplayNode{
public:
  DisplayNode(ConcatNode<T>* node, int node_depth);
  void setNext(DisplayNode<T>* nextNode);
  DisplayNode<T>* getNext();
  ConcatNode<T>* getValue();
  int getNodeDepth();
private:
  ConcatNode<T>* m_node;
  DisplayNode<T>* m_next;
  int m_node_depth;
};
#include "displaynode.hpp"
#endif
