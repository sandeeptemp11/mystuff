#include <bits/stdc++.h>
using namespace std;

#define ll      long long int
#define vl      vector<ll>
#define vvl     vector<vl>
#define vb      vector<bool>
#define vvb     vector <vb>
#define vpl     vector<pl>
#define vvpl    vector <vpl>
#define vs      vector<string>
#define mk make_pair
#define fi first
#define se second
#define f(i, a, b) for (ll i = a; i <= b; i++)
#define rf(i, a, b) for (ll i = a; i >= b; i--)

// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vvb dp(1+n, vb (1+k, 0));
//     // can do space optimize to O(k)
//     dp[0][0] = 1;
//     f(i, 1, n){
//         f(s, 0, k){
//             dp[i][s] = dp[i-1][s];
//             if(s - arr[i-1] >= 0) dp[i][s] = (dp[i][s] || dp[i-1][s - arr[i-1]]);
//         }
//         if(dp[i][k]) return true;
//     }
//     return false;
// }

// space optimized code arr[i] >= 0, k >= 0 **
// time : O(n*k)
// space: O(k)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vb dp(1+k, 0);
    dp[0] = 1;
    f(i, 0, n-1){
        rf(s, k, 0) {
            if (s - arr[i] >= 0) dp[s] = (dp[s] || dp[s - arr[i]]);
        }
        if(dp[k]) return true;
    }
    return false;
}
