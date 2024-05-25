#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    int arr[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) cin >> arr[i][j];
    }

    int dp[m][n] = {};
    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(i == m-1 && j == n-1) dp[i][j] = 0;
            else if(i == m-1){
                dp[i][j] = max(abs(arr[i][j] - arr[i][j+1]), dp[i][j+1]);
            }else if(j == n-1){
                dp[i][j] = max(abs(arr[i][j] - arr[i+1][j]), dp[i+1][j]);
            }else{
                dp[i][j] = min(max(abs(arr[i][j] - arr[i][j+1]), dp[i][j+1]), max(abs(arr[i][j] - arr[i+1][j]), dp[i+1][j]));
            }
        }
    }
    cout << dp[0][0] << "\n";
}
