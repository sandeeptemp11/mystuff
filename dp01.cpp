// another approach
int longestCommonSubsequence(string a, string b){
    #define vl vector <ll>
    #define ll long long int
    
    ll n = a.size();
    ll m = b.size();
    vector <vector <ll>> dp(1+n, vl(1+m, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
        }
    }
    return dp[n][m];
}

int longestPalindromeSubseq(string str) {
    string rev;
    rev = str;
    reverse(rev.begin(), rev.end());
    return longestCommonSubsequence(str, rev);
}
