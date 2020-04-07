#ifndef CONCATQUEUE_H
#define CONCATQUEUE_H

template <typename T>
class ConcatenatedQueue{
public:
  //ConcatenatedQueue(){}
  virtual bool isEmpty() = 0;
  virtual void build() = 0;
  virtual void insert(T val) = 0;
  virtual void deleteMin() = 0;
  virtual void preorder() = 0;
  virtual void inorder() = 0;
  virtual void levelorder() = 0;
  virtual ~ConcatenatedQueue(){}
};

#endif
