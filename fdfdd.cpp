#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int q;
    cin >> q;
    int arr[1+n];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    vector <int> pref(1+n, 0);
    for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + arr[i];


    for(int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l-1] << " ";
    }
    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}
