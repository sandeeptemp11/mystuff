#include <iostream>
#include <algorithm>
using namespace std;
// finding frequencies
int main(){
    int n;
    cin >> n;

    int arr[1+n];
    for(int i = 1; i <= n; i++) cin >> arr[i];

    sort(arr+1, arr+n+1);
    for(int i = 1; i <= n; i++){
        int l = lower_bound(&arr[i], &arr[n], arr[i]) - arr;
        int u = upper_bound(&arr[i], arr+n+1, arr[i]) - arr - 1;
        cout << arr[i] << " : " << u-l+1 << "\n";
        i = u;
    }
}
