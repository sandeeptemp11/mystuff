#include <bits/stdc++.h>
using namespace std;

// (high - low) steps
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while(i <= j){
        while(i <= j && arr[i] <= pivot) i++;
        while(i <= j && arr[j] > pivot) j--;
        if(i < j){
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    swap(arr[i - 1], arr[low]);
    return i - 1;
}

void quick_sort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi + 1, high);
    }
}

int main(){
    int n; // number of elements
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    quick_sort(arr, 0, n-1);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}
