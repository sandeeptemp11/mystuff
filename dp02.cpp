string longestPalindrome(string s) {
    int n = s.size();
    vector <vector<int>> dp(1+n, vector <int>(1+n, 0));
    // dp[i][j] = i - j + 1 (if s from j to i is palindrome)
    // dp[i][j] = 0         (otherwise)
    int ans = 1;
    int low = 0;
    int high = 0;
    for(int i = 1; i <= n; i++){
        dp[i][i] = 1;
        for(int j = i-1; j >= 1; j--){
            if(s[i-1] == s[j-1]){
                if(i - 1 < j + 1) dp[i][j] = 2;
                else if(dp[i-1][j+1] != 0) dp[i][j] = 2 + dp[i-1][j+1];
            }
            if(dp[i][j] > ans){
                ans = dp[i][j];
                high = i-1;
                low = j-1;
            }
        }
    }
    return s.substr(low, high - low + 1);
}
