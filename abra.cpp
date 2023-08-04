#include <iostream>
using namespace std;
// wrong
void Swap(int& a, int& b ){
	a ^= b;
	b ^= a;
	a ^= b;
}

int main(){
	int a = 5;
	Swap(a, a);
	cout << a << "\n";
}
