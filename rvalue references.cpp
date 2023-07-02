// C++ program to illustrate rvalue
#include <iostream>
using namespace std;

// Declaring rvalue reference to the
// rvalue passed as the parameter
void printReferenceValue(int&& x)
{
	cout << x << endl;
}

// Driver Code
int main()
{
int a = 10;

// Declaring lvalue reference
int& lref = a;

// Declaring rvalue reference
int&& rref = 20;
rref = 25;
// int&& rref = lref; error because rvalue reference cannot bind to an lvalue reference
// int&& rref = a; error because rvalue reference cannot bind to an lvalue reference

cout << lref << " " << rref << "\n";
}
