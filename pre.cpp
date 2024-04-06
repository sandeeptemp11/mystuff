#include <bits/stdc++.h> 
int knapsack(vector<int> w, vector<int> v, int n, int W){
	vector <vector <int>> dp(1+n, vector <int>(W+1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= W; j++){
			dp[i][j] = dp[i-1][j];
			if(j >= w[i-1]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
		}
	}
	// we can print the items
	// 0-base indices are set in index vector
	vector <bool> indices(n, false);

	// going reverse
	// time of below code to find items is O(n) given dp
	int i = n;
	int j = W;
	while(i > 0){
		if(dp[i-1][j] == dp[i][j]) i--;
		else{
			indices[i-1] = true;
			i--;
			j -= w[i-1];
		}
	}
	for(int i = 0; i < n; i++) if(indices[i]) cout << i << " ";
	cout << "\n";
	
	return dp[n][W]; 
}
