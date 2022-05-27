main:
	g++ main.cpp -I/usr/local/lib/restbed/distribution/include -L /usr/local/lib/restbed/distribution/library -lrestbed libs/json.hpp libs/mathLib.o -o dist/main
libs:
	g++ -c libs/mathLib.cpp -o libs/mathLib.o
run:
	LD_LIBRARY_PATH=/usr/local/lib/restbed/distribution/library ./dist/main
