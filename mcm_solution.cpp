int matrixMultiplication(int n, int arr[]){
    n--;
    vector <vector <int>> dp(2+n, vector <int> (2+n, 0));
    
    for(int len = 2; len <= n; len++){
        for(int i = 1; i <= n-len+1 ; i++){
            int j = i + len - 1;
            // matrices from i to j
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++){ 
                // splitting at k
                // Ai:k, A(k+1):j
                dp[i][j] = min(dp[i][j], arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j]);
            }
        }
    }
    
    return dp[1][n]; 
}
