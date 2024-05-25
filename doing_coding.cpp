#include <bits/stdc++.h>
using namespace std;


bool isValid(int i, int j, int parent, int diff, vector <vector<bool>>& visited, vector <vector<int>>& arr){
    int m = visited.size();
    int n = visited[0].size();
    if(i < 0 || j < 0 || i >= visited.size() || j >= visited[0].size() || visited[i][j] || abs(parent - arr[i][j]) > diff){
        return false;
    }
    if(i == m-1 && j == n-1) return true;
    visited[i][j] = true;
    if(isValid(i-1, j, arr[i][j], diff, visited, arr)) return true;
    if(isValid(i, j-1, arr[i][j], diff, visited, arr)) return true;
    if(isValid(i+1, j, arr[i][j], diff, visited, arr)) return true;
    if(isValid(i, j+1, arr[i][j], diff, visited, arr)) return true;
    return false;
}

int main(){
    int m, n;
    cin >> m >> n;

    vector <vector <int>> arr(m, vector <int>(n));
    int min_ele = INT_MAX;
    int max_ele = INT_MIN;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            min_ele = min(min_ele, arr[i][j]);
            max_ele = max(max_ele, arr[i][j]);
        }
    }
    int low = 0;
    int high = max_ele - min_ele;
    while(low <= high){
        int diff = (high + low)/2;
        vector <vector <bool>> visited(m, vector <bool> (n, false));
        if(isValid(0, 0, arr[0][0], diff, visited, arr)){
            high = diff - 1;
        }else{
            low = diff + 1;
        }
    }
    cout << low << "\n";
}
