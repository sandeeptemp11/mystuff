#include <bits/stdc++.h>
using namespace std;

// Time complexity : theta(log y)
// Space complexity : theta(1)
long long int power(long long int x, long long int y){
    if(x == 1) return x;
    long long int ans = 1;
    while(y > 0){
        if(y&1) ans *= x;
        y = y >> 1;
        x *= x;
    }
    return ans;
}

int main(){
    long long int x,y;
    cin >> x >> y;

    cout << power(x, y) << "\n";
}
