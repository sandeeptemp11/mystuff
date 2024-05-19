int mod = 1e9 +7;
int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector <vector <int>> dp(1+n, vector <int> (1+m, 0));
    for(int i = 0; i <= n; i++) dp[i][0]  = 1;  // base case
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j]; 
            if(s[i-1] == t[j-1]){
                dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod;
            }
        }
    }
    return dp[n][m];
}
