#include <iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int arr[1+n];
    for(int i = 1; i <= n; i++) cin >> arr[i];

    int min, max;
    int i;
    if(n%2==0){
        if(arr[1] < arr[2]){
            min = arr[1];
            max = arr[2];
        }else{
            min = arr[2];
            max = arr[1];
        }
        i = 3;
    }else{
        min = arr[1];
        max = arr[1];
        i = 2;
    }
    while(i < n){
        if(arr[i] < arr[i+1]){
            if(arr[i+1] > max) max = arr[i+1];
            if(arr[i] < min) min = arr[i];
        }else{
            if(arr[i] > max) max = arr[i];
            if(arr[i+1] < min) min = arr[i+1];
        }
        i += 2;
    }
    cout << "Maximum: " << max << "\n";
    cout << "Minimum: " << min << "\n";
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();
}
