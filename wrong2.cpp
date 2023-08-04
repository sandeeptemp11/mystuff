#include <iostream>
using namespace std;
int main()
{
	long long int a = 1 << 60; // compilation error warning overflow
	cout << a << "\n";
	return 0;
}
