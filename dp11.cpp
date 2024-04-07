int lcs(string &str1, string &str2) {
  // Write your code here.
  int n1 = str1.size();
  int n2 = str2.size();
  vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
  // dp[i][j] is the length of longest substring which ends at index i-1 in str1
  // ans j-1 in str2
  int len = 0;
  for (int i = 1; i <= n1; i++){
      for(int j = 1; j <= n2; j++){
          if(str1[i-1] == str2[j-1]) dp[i][j] =  1 + dp[i-1][j-1];
          len = max(len, dp[i][j]);
      }
  }
  return len;
}
