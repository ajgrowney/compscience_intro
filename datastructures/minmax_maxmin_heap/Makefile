MyHeap: main.o
	g++ main.o -std=c++11 -g -Wall -o MyHeap
main.o: HeapInterface.h maxminheap.h maxminheap.hpp maxminheap.h maxminheap.hpp main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

clean:
	rm *.o MyHeap
