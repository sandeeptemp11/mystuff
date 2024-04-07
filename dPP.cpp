int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector <vector <int>> dp(1+n, vector <int>(1+W, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(j >= weight[i-1]) dp[i][j] = max(dp[i-1][j], dp[i][j-weight[i-1]] + profit[i-1]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}
