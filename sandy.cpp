#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    // m x n matrix
    int arr[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) cin >> arr[i][j];
    }

    vector <vector<int>> pref(1+m, vector <int>(1+n, 0));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++) pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + arr[i-1][j-1];
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++) cout << pref[i][j] << " ";
        cout << "\n";
    }
}
