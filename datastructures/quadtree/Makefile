Lab5: main.o Executive.o
	g++ main.o Executive.o -std=c++11 -g -Wall -o Lab5
main.o: Executive.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
Executive.o: Executive.h linkedlist.h linkedlist.hpp node.h node.hpp Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp
clean:
	rm *.o Lab5
