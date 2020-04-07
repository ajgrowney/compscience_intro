#ifndef SKEWNODE_H
#define SKEWNODE_H
#include "concatnode.h"

template<typename T>
class SkewNode: public ConcatNode<T>{
public:
  SkewNode(T val);
  void setLST(SkewNode<T>* new_lst);
  void setRST(SkewNode<T>* new_rst);
  T getValue();
  SkewNode<T>* getRST();
  SkewNode<T>* getLST();
  ~SkewNode();
private:
  SkewNode<T>* lst;
  SkewNode<T>* rst;
  T m_value;
};
#include "skewnode.hpp"
#endif
