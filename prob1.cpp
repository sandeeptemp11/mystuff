// For each 1 <= j <= n, find minimum possible index i such that i < j and a[i] > a[j]
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fi first 
#define se second 


int main(){
    int n;
    cin >> n;

    pair<int,int> arr[n];
    for(int i = 0; i < n; i++){
        arr[i].se = i;
        cin >> arr[i].fi;
    }
    sort(arr, arr+n);

    int suff[n];
    suff[n-1] = arr[n-1].se;
    int ans[n];
    ans[arr[n-1].se] = -1;
    for(int i = n-2; i >= 0; i--){
        suff[i] = min(suff[i+1], arr[i].se);
        if(suff[i+1] < arr[i].se) ans[arr[i].se] = suff[i+1];
        else ans[arr[i].se] = -1;
    }
    for(int i = 0; i <= n-1; i++) cout << ans[i] << " ";
    cout << "\n";
}

/*
Input:
6
7 6 9 5 10 9

Output:
-1 0 -1 0 -1 4
*/
