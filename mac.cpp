#include <iostream>
using namespace std;

// Print all the sub-arrays of an array
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "All " <<  n*(n+1)/2 + 1 << " sub-arrays of given array :\n";
    cout << "[ ]" << "\n";
    for(int i = 0; i < n; i++){
        cout << "Sub-arrays starting with index " << i << "\n";
        for(int j = i; j < n; j++){
            cout << "Sub-array arr[" << i << ":" << j << "] : ";
            for(int k = i; k <= j; k++) cout << arr[k] << " ";
            cout << "\n";
        }
    }
    cout << "\n";
}
