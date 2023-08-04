#include <iostream>
using namespace std;


void Swap(int& a, int& b ){
	if(a==b) return;
	a ^= b;
	b ^= a;
	a ^= b;
}

int main(){
	int a = 5;
	Swap(a, a);
	cout << a << "\n";
}
