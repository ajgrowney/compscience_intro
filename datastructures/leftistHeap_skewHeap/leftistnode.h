#ifndef LEFTISTNODE_H
#define LEFTISTNODE_H
#include "concatnode.h"

template <typename T>
class LeftistNode: public ConcatNode<T>{
public:
  LeftistNode(T val);
  //Getter Functions
  int getRank();
  T getValue();
  LeftistNode<T>* getRST();
  LeftistNode<T>* getLST();

  //Setter Functions
  void setRank(int current_rank);
  int findRank(int current_rank);
  void setLST(LeftistNode<T>* new_lst);
  void setRST(LeftistNode<T>* new_rst);
  ~LeftistNode();

private:
  LeftistNode<T>* lst;
  LeftistNode<T>* rst;
  int rank;
  T m_value;

};
#include "leftistnode.hpp"
#endif
