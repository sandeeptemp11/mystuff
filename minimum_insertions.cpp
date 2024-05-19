int minInsertions(string s) {
    int n = s.size();
    vector <vector <int>> dp(1+n, vector <int> (1+n, 0));
    for(int i = 1; i <= n; i++){
        dp[i][i] = 0;
        for(int j = i-1; j >= 1; j--){
            if(s[i-1] == s[j-1]){
                dp[i][j] = dp[i-1][j+1];
            }else{
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j+1]);
            }
        }
    }
    return dp[n][1];
}
