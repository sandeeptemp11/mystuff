#define ll long long int
class Solution {
  public:
    long long int count(int coins[], int n, int sum) {
        vector <vector <long long int>> dp(1+n, vector <ll> (1+sum, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(j >= coins[i-1]) dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]; // important note that we use i in dp[i][j-coins[i-1]] :)
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};
