// int cutRod(vector<int> &price, int n){
// 	vector <int> dp(1+n, 0);
// 	for(int l = 1; l <= n; l++){
// 		dp[l] = price[l-1];
// 		for(int k = 1; k <= l-1; k++) dp[l] = max(dp[l], dp[l-k] + dp[k]);
// 	}
// 	return dp[n];
// }

// optimizing more
int cutRod(vector<int> &price, int n){
	vector <int> dp(1+n, 0);
	for(int l = 1; l <= n; l++){
		dp[l] = price[l-1];
		for(int k = 1; k <= l/2; k++) dp[l] = max(dp[l], dp[l-k] + dp[k]);
	}
	return dp[n];
}
