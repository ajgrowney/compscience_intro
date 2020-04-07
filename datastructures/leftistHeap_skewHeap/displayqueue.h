#ifndef DISPLAYQUEUE_H
#define DISPLAYQUEUE_H
#include "displaynode.h"
#include "concatnode.h"
template <typename T>
class DisplayQueue{
public:
  DisplayQueue();
  bool isEmpty() const;
  int getSize();
  int getDepth();
  void increaseDepth();
  int getFrontDepth();
  void resetDepth();
  ConcatNode<T>* peek() const;
  void dequeue();
  void enqueue(ConcatNode<T>* nextNode, int depth);
private:
  DisplayNode<T>* m_front;
  int m_size;
  int m_depth;
};
#include "displayqueue.hpp"
#endif
