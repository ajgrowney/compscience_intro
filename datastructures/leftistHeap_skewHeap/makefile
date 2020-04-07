LeftistSkew: main.o
	g++ main.o -std=c++11 -g -Wall -o LeftistSkew

main.o: concatnode.h displaynode.h displaynode.hpp displayqueue.h displayqueue.hpp concatqueue.h leftistnode.h leftistnode.hpp leftistheap.h leftistheap.hpp skewnode.h skewnode.hpp skewheap.h skewheap.hpp main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
clean:
	rm *.o LeftistSkew
