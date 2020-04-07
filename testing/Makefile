#	Author: John Gibbons
#	Date: 2016.10.26


#Add needed TestSuite.o
prog: main.o TestSuite.o
	g++ -g -Wall -std=c++11 main.o TestSuite.o LinkedListOfInts.o -o prog


main.o: main.cpp TestSuite.h
	g++ -g -Wall -std=c++11 -c main.cpp


TestSuite.o: TestSuite.h LinkedListOfInts.h TestSuite.cpp
	g++ -g -Wall -std=c++11 -c TestSuite.cpp


#DON'T delete LinkedList.o!
clean:
	rm main.o *.*~ prog
