#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void MCM(int low, int high, const int p[], vector <vector<int>>& dp);
int get(int low, int high, const int p[], vector <vector<int>>& dp);

void solve(const int& n, const int p[]){
    cout << "Optimal value (Minimum number of sclar multiplications):\n";
    vector <vector <int>> dp(1+n, vector <int> (1+n, -1));
    MCM(1, n, p, dp);
    cout << dp[1][n] << "\n";
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n; // number of matrices

        int p[1+n]; // dimension of ith matrix is p[i-1]Xp[i]
        for(int i = 0; i <= n; i++){
            cin >> p[i];
        }
        solve(n, p);
    }
}
// recursive program without memorization
void MCM(int low, int high, const int p[], vector <vector<int>>& dp){
    if(low == high){
        dp[low][high] = 0;
        return;
    }
    int cost = INT_MAX;
    for(int k = low; k < high; k++){
        cost = min(cost, get(low, k, p, dp) + get(k + 1, high, p, dp) + p[low - 1] * p[k] * p[high]);
    }
    dp[low][high] = cost;
    return;
}

int get(int low, int high, const int p[], vector <vector<int>>& dp){
    if(dp[low][high] == -1) MCM(low, high, p, dp);
    return dp[low][high];
}
