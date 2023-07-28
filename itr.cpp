#include <bits/stdc++.h>
using namespace std;

int binarySearch(int low, int high, int arr[], int key){
    while(low <= high){
        int mid = (high + low)/2;
        if(arr[mid] < key) low = mid + 1;
        else if(arr[mid] > key) high = mid - 1;
        else return mid;
    }
    return -1;
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
