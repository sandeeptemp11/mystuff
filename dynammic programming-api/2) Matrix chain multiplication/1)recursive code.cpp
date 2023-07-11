#include <iostream>
#include <climits>
using namespace std;

// recursive program without memorization
int MCM(int low, int high, const int p[]){
    if(low == high){
        return 0;
    }
    int cost = INT_MAX;
    for(int k = low; k < high; k++){
        cost = min(cost, MCM(low, k, p) + MCM(k + 1, high, p) + p[low - 1] * p[k] * p[high]);
    }
    return cost;
}


void solve(const int& n, const int p[]){
    cout << "Optimal value (Minimum number of sclar multiplications):\n";
    cout << MCM(1, n, p) << "\n";
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n; // number of matrices

        int p[1+n]; // dimension of ith matrix is p[i-1]Xp[i]
        for(int i = 0; i <= n; i++){
            cin >> p[i];
        }
        solve(n, p);
    }
}
