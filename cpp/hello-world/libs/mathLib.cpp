// MathLibrary.cpp
// compile with: cl /c /EHsc MathLibrary.cpp
// post-build command: lib MathLibrary.obj

namespace MathLibrary
{
    	namespace Arithmetic {
	double Add(double a, double b){
        	return a + b;
    	}

    	double Subtract(double a, double b)
    	{
        	return a - b;
    	}

    	double Multiply(double a, double b)
    	{
        	return a * b;
    	}

    	double Divide(double a, double b)
    	{
        	return a / b;
    	}
	}
}
