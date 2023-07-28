#include <iostream>
#include <vector>
using namespace std;

void merge(int low, int mid, int high, int arr[]){
    int n1 = mid -low + 1;
    int n2 = high - mid;

    vector <int> l, r;
    for(int i = low; i <= mid; i++) l.push_back(arr[i]);
    for(int i = mid + 1; i <= high; i++) r.push_back(arr[i]);

    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        if(l[i] < r[j]) arr[k++] = l[i++];
        else arr[k++] = r[j++];
    }
    while(i < n1) arr[k++] = l[i++];
    while(j < n2) arr[k++] = r[j++];
    return;
}

void mergeSort(int low, int high, int arr[]){
    if (low < high){
        int mid = (high + low)/2;
        mergeSort(low, mid, arr);
        mergeSort(mid + 1, high, arr);
        merge(low, mid, high, arr);
    }
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(0, n - 1, arr);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}
