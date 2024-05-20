#include <bits/stdc++.h>
using namespace std;

void print_optimal_parenth(vector <vector <int>>& split, int i, int j){
    if(i == j){
        cout << " A" << i << " ";
        return;
    }
    cout << "(";
    print_optimal_parenth(split, i, split[i][j]);
    print_optimal_parenth(split, split[i][j] + 1, j);
    cout << ")";
}

int main(){
    int n; // number of matrices
    cin >> n;

    int dim[n+1]; // dimension array
    for(int i = 0; i <= n; i++) cin >> dim[i];

    int dp[1+n][1+n] = {};      // cost matrix
    vector <vector <int>> split(1+n, vector <int> (1+n, 0));   // split matrix
    for(int len = 2; len <= n; len++){
        for(int i = 1; i + len - 1 <= n; i++){  
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++){
                int cost_at_split_k = dim[i-1]*dim[k]*dim[j] + dp[i][k] + dp[k+1][j];
                if(dp[i][j] > cost_at_split_k){
                    dp[i][j] = cost_at_split_k;
                    split[i][j] = k;
                }
            }
        }
    }
    cout << "The optimal cost: " << dp[1][n] << "\n";
    cout << "An optimal split:\n";
    print_optimal_parenth(split, 1, n);
}
