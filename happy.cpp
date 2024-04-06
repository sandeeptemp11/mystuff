#define ll long long int
int findWays(vector<int>& arr, int k){
	// this is an easy question but what if the elements are negative ??
	// i think you need to use maps
	ll n = arr.size();
	vector <vector <int>> dp(1+n, vector <int>(1+k, 0));
	dp[0][0] = 1;
	int mod = 1e9 + 7;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			dp[i][j] = dp[i-1][j];
			if(j - arr[i-1] >= 0) dp[i][j] = (dp[i][j] + dp[i-1][j-arr[i-1]])%mod;
		}
	}
	return dp[n][k];
}
