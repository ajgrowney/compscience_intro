all:
	g++ -std=c++14 -I"/usr/local/lib/restbed/distribution/include" main.cpp -L"/usr/local/lib/restbed/distribution/library" -lrestbed libs/json.cpp -o program
prog:
	g++ -std=c++14 -o program main.o json.o -L"/usr/local/lib/restbed/distribution/library" -lrestbed
json.o:
	g++ -std=c++14 -c libs/json.cpp -o json.o
main.o:
	g++ -std=c++14 -I"/usr/local/lib/restbed/distribution/include" -c main.cpp -o main.o
run:
	LD_LIBRARY_PATH=/usr/local/lib/restbed/distribution/library ./program
clean:
	rm *.o