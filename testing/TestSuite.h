#ifndef TESTSUITE_H
#define TESTSUITE_H
#include <iostream>
#include "LinkedListOfInts.h"

class TestSuite{

public:
  TestSuite(LinkedListOfInts importedTestList);
  void runTests();
  bool testIsEmpty();
  bool testAddBack(int newVar);
  bool testAddFront(int newVar);
  bool testRemoveFront();
  bool testRemoveBack();
  bool testSize();
private:
  LinkedListOfInts testList;
  int manualListCount;
};

#endif
