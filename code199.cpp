#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define f(i, a, b) for(int i = a; i <= b; i++)

int main(){
    // bowling
    int n; cin >> n;
    int val[n]; 
    for(int i = 0; i < n; i++) cin >> val[i];
    
    // dp[i] = maximum value (optimal solution) for 0, 1, 2, .., i-1 values
    ll dp[n];
    dp[0] = max(0, val[0]);

    f(i, 1, n-1){
        dp[i] = max(0, val[i]) + dp[i-1];
        if(i >= 2) dp[i] = max(dp[i], val[i]*val[i-1] + dp[i-2]);
    }
    cout << dp[n-1] << "\n";
}

/*
Input:
8
-3 1 1 9 9 2 -5 -5

Output:
110
*/
