// radix sort algo
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void counting_sort(int arr[], vector <int>& count, vector <int>& b, int n, int d){
    for(int i = 0; i < n; i++) count[arr[i]/d%10]++;
    for(int i = 1; i <= 9; i++) count[i] += count[i-1];
    for(int i = n - 1; i >= 0; i--) b[--count[arr[i]/d%10]] = arr[i];
    return;
}

int normalize(int arr[], int n){
    int min_ele = *min_element(arr, arr+n);
    if(min_ele < 0){
        for(int i = 0; i < n; i++) arr[i] += -min_ele;
        return min_ele;
    }
    return 0;
}

void denormalize(int arr[], int n, int nf){
    for(int i = 0; i < n; i++) arr[i] += nf;
    return;
}

void radix_sort(int arr[], int n){
    int d = 1;
    vector <int> count(10), b(n);
    int nf = normalize(arr, n);
    int max_ele = *max_element(arr, arr+n); // max_element should be found after normalizing
    while(max_ele > 0){
        fill(count.begin(), count.end(), 0);
        counting_sort(arr, count, b, n, d);
        copy(b.begin(), b.end(), arr);
        max_ele /= 10;
        d *= 10;
    }
    denormalize(arr, n, nf);
    return;
}

int main(){
    int n; // number of elements
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    radix_sort(arr, n);
    cout << "Sorted form:\n";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}
