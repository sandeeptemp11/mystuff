class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        // cache benifit
        int n = coins.size();
        vector <vector <long long int>> dp(1+n, vector <long long int> (amount + 1, INT_MAX));
        // dp[i][j] - minimal coins needed to get j using coins 0, 1, .. , i
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int a = 0; a <= amount; a++){
                dp[i][a] = dp[i-1][a]; // without using ith coin
                if(a >= coins[i-1]) dp[i][a] = min(dp[i][a], dp[i][a - coins[i-1]] + 1 );
            }
        }
        return dp[n][amount] >= INT_MAX ? -1 : (int)dp[n][amount];
    }
};
