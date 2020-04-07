#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "linkedlist.h"
#include <string>
#include <fstream>
#include <stdexcept>

class Executive{
public:
    //constructor
    Executive();
    //will run the program
    void run();
    int CN=0;
    //runs simple cells program
    void reportSimpleCellsIn(int Q[64][64], int frontRow, int lastRow, int firstColumn, int lastColumn);
    int sum(int arr[], int n);
    void partitionInteger(int n,int arr[], int i);
    void partitionIntegerWith(int n, int arr[], int i);
    //destructor
    ~Executive();
private:
    int menuChoice;

    LinkedList<std::string> revList;
};

#endif
