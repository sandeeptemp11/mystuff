
#include <iostream>
using namespace std;

void updateAndPrint(const int diff[], int arr[], const int& n){
    arr[0] = diff[0];
    cout << arr[0] << " ";
    for(int i = 1; i < n; i++){
        arr[i] = diff[i] + arr[i-1];
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 1; i <= n; i++) cin >> arr[i-1];

    int diff[n];
    diff[0] = arr[0];
    for(int i = 1; i < n; i++) diff[i] = arr[i] - arr[i-1];
    
    int q;
    cin >> q;
    while(q--){
        char ch;
        cin >> ch;

        if(ch == 'p') updateAndPrint(diff, arr, n);
        else{
            int l, r, x;
            cin >> l >> r >> x;
            diff[l] += x;
            if(r != n-1) diff[r+1] -= x;
        }
    }

}
