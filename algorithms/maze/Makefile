Maze: main.o MazeReader.o MazeCreationException.o RecWalk.o 
	g++ main.o MazeReader.o RecWalk.o -std=c++11 -g -Wall -o Maze
main.o: MazeReader.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
MazeReader.o: MazeCreationException.h RecWalk.h MazeReader.h MazeReader.cpp
	g++ -std=c++11 -g -Wall -c MazeReader.cpp
MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -std=c++11 -g -Wall -c MazeCreationException.cpp
RecWalk.o: RecWalk.h RecWalk.cpp
	g++ -std=c++11 -g -Wall -c RecWalk.cpp

clean:
	rm *.o Maze
