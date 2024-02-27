#include <iostream>
using namespace std;

bool isPair(int arr[], int k, int n){
    int low = 0;
    int high = n - 1;
    while(low < high){
        if(arr[low] + arr[high] == k) return true;
        else if(arr[low] + arr[high] > k) high--;
        else low++;
    }
    return false;
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    if(isPair(arr, n, k)){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}
