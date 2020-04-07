#ifndef HEAPINTERFACE_H
#define HEAPINTERFACE_H

template <typename T>

class HeapInterface
{
public:
    //preconditions: there is a implemented Heap to check if empty
    //postconditions: none
    //return: if the Heap is empty or not
  virtual bool isEmpty() const= 0;
  //Pre:Take in a value to be inserted into the heap for bottom up intiailization
  //Post: There is another element in the heap, will increase num_elements
  //Return: No return value needed
  virtual void insert_bottomup(T val) = 0;
  //Pre: Takes the heap structure that is currently being held
  //Post: Restructures it to its appropriate min, max, minmax, maxmin type
  //Return: No return needed
  virtual void buildheap() = 0;
  //Pre: Takes in a value to be inserted into the heap individually
  //Post: Places and moves to correct place in the heap
  //Return: No return needed
  virtual void insert_upheap(T val) = 0;
  //Pre: No parameters, existing heap
  //Post: Finds the minimum value and deletes it from the heap
  //Return: True if deleted, false if failed
  virtual bool deleteMin() = 0;
  //Pre: No parameters, existing heap
  //Post: prints out the minimum value in the heap
  //Return: returns its location in the array
  virtual int findMin() = 0;
  //Pre: No parameters, existing heap
  //Post: prints out max value in the heap
  //Return: returns its location in the array
  virtual int findMax() = 0;
  //Pre: No parameters, existing heap
  //Post: finds the max value in the heap and deletes it
  //Return: true if deleted, false if failed
  virtual bool deleteMax() = 0;
  //Pre: No parameters
  //Post: Makes no change to the data structure
  //Return: Prints out the heap to the screen but does not return a value
  virtual void levelOrder() = 0;

private:
  int k;
  int num_elements;
};

#endif
