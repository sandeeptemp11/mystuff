// the below code will not work (very nice bug)
// because you are not counting sub-sets summing to zero in the below code 

#define ll long long int
int findWays(vector<int>& arr, int k){
	ll n = arr.size();
	vector <vector <int>> dp(1+n, vector <int>(1+k, 0));
	dp[0][0] = 1;
	int mod = 1e9 + 7;
	for(int i = 1; i <= n; i++){
		dp[i][0] = 1;
		for(int j = 1; j <= k; j++){
			dp[i][j] = dp[i-1][j];
			if(j - arr[i-1] >= 0) dp[i][j] = (dp[i][j] + dp[i-1][j-arr[i-1]])%mod;
		}
	}
	return dp[n][k];
}
