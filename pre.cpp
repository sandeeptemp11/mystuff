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
			j -= w[i-1];
			i--;
		}
	}
	for(int i = 0; i < n; i++) if(indices[i]) cout << i << " ";
	cout << "\n";
	
	return dp[n][W]; 
}


/*
Test cases:

test_case 1)
	n = 7, W = 20
	w = [6, 5, 1, 5, 6, 5, 9]
	v = [5, 3, 4, 9, 6, 1, 1]
 Output:	
 	Maximum value: 24
  	Items in knapsack (0-base indexing) : 0, 2, 3, 4

test_case 2)
	n = 3, W = 50
	w = [10, 20, 30]
	v = [60, 100, 120]
 Output:	
 	Maximum value: 220
  	Items in knapsack (0-base indexing) : 1, 2

*/
