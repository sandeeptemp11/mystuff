#include <bits/stdc++.h>
using namespace std;

void myswap(int&x, int&y){
    if(x == y) return; // this edge case is important when x and y point to the same identifier.
    x ^= y;
    y ^= x;
    x ^= y;
}

int main(){
    int x = 3, y = 4;
    myswap(x, y);
    cout << x << ", " << y << "\n";
}
