#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int g = gcd(b, a%b, x, y);
    int temp_y = y;
    y = x - (a/b)*y;
    x = temp_y;
    return g;
}

int main(){
    int a, b;
    cin >> a >> b;
    int x, y;
    int g = gcd(a, b, x, y);
    cout << a << "*" << x << " + " << b << "*" << y << " = " << g << "\n";
}
