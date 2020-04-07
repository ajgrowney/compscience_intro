#ifndef CONCATNODE_H
#define CONCATNODE_H

template<typename T>
class ConcatNode{

public:
  virtual T getValue() = 0;

private:
  T m_value;
};
#endif
