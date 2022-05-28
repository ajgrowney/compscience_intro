#include <iostream>
#include <map>
#include <vector>
#include "mathLib.h"

using namespace MathLibrary::Arithmetic;
using namespace std;
const std::string STRIPCHARS = " \n\r\t\f\v\"";

template <typename T>
void print(T s) { cout << s << endl; }

int main(int argc, char* argv[])
{
	print("Hello World! Let's add some numbers:");
	float val1 = 1.1;
	float val2 = 2.2;
	double c = Add(val1, val2);
	print(c);
	return 0;
}
