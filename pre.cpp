// 0-1 knapsack
#include <bits/stdc++.h> 
int knapsack(vector<int> w, vector<int> v, int n, int W){
	vector <vector <int>> dp(1+n, vector <int>(W+1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= W; j++){
			dp[i][j] = dp[i-1][j];
			if(j >= w[i-1]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
		}
	}
	return *max_element(dp[n].begin(), dp[n].end());
}
