#include <bits/stdc++.h>
using namespace std;

int binarySearch(int low, int high, int arr[], int key){
    if(low > high) return -1;
    int mid = (low + high)/2;
    if(arr[mid] < key) return binarySearch(mid + 1, high, arr, key);
    else if(arr[mid] > key) return binarySearch(low, mid - 1, arr, key);
    else return mid;
}

int main(){
    int n;
    cin >> n;

    int key;
    cin >> key;

    /*Array is sorted*/
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int index = binarySearch(0, n-1, arr, key);
    if(index == -1) cout << "Not found\n";
    else cout << "Found at index: " << index << "\n";
}
