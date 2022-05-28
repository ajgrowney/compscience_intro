# Hello Rest
### Goal: Learn how to install a c++ library
### Success Criteria: Can host a basic HTTP API Server like Flask


## Restbed
Looks like a good candidate as it has lots of GitHub stars and easy intro example

### Installation
- https://github.com/Corvusoft/restbed#build

## What I learned
1. Compiling is crazy. 
2. First step of compiling is .c -> .o 
3. Second step is linking your .o files (and including third party libraries)

** Important: cmake file shows that the installed location is the distribution folder
## Compiling
### On Your Own
1. Make .o files for json, mathLib
- `g++ -std=c++14 -c libs/json.cpp -o json.o`
- `g++ -std=c++14 -c libs/mathLib.cpp -o math.o`
2. Make the .o file for main
- `g++ -std=c++14 -I"/usr/local/lib/restbed/distribution/include" -c main.cpp -o main.o`
3. Link the .o files and output a program
- `g++ -std=c++14 -o program main.o math.o json.o -L"/usr/local/lib/restbed/distribution/library" -lrestbed`

### Using the Makefile: Long Form
1. `make json.o`
2. `make math.o`
3. `make main.o`
4. `make prog`

### Using the Makefile: Short Form
1. `make all`

## Running
Option 1 - Makefile: `make run`

Option 2 - Command: `LD_LIBRARY_PATH=/usr/local/lib/restbed/distribution/library ./program`

*Note: We have to include the LD_LIBRARY_PATH so it knows where to find the restbed functions* 