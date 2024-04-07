class Solution {
public:
    int longestPalindromeSubseq(string str) {
        int n = str.size();
        vector <vector <int>> dp(1+n, vector <int>(1+n, 0));
        // dp[i][j] is the length of the longest palindromic subsequence
        // from j to i
        for(int i = 1; i <= n; i++){
            dp[i][i] = 1;
            for(int j = i-1; j >= 1; j--){
                // string str from j to i (inclusive)
                dp[i][j] = max(dp[i-1][j], dp[i][j+1]);
                if(str[i-1] == str[j-1]) dp[i][j] = max(dp[i][j], 2 + dp[i-1][j+1]);
            }
        }
        return dp[n][1];
    }
};
