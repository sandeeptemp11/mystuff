// counting sort
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void counting_sort(vector <int>& arr, int n){
    // arr[i] >= 0 for all 0 <= i <= n-1
    int max_ele = *max_element(arr.begin(), arr.end());
    if(max_ele == 0) return; // edge case
    
    vector <int> freq(1+max_ele, 0);
    for(int i = 0; i < n; i++) freq[arr[i]]++;
    for(int i = 1; i <= max_ele; i++) freq[i] += freq[i-1];
    
    int copy_arr[n];
    copy(arr.begin(), arr.end(), copy_arr);
    for(int i = n-1; i >= 0; i--){
        arr[--freq[copy_arr[i]]] = copy_arr[i];
    }
}

void sort_arr(vector <int>& arr, int n){
    int min_ele = *min_element(arr.begin(), arr.end());
    if(min_ele < 0){
        for(int i = 0; i < n; i++) arr[i] += -1*min_ele;
    }
    counting_sort(arr, n);
    if(min_ele < 0){
        for(int i = 0; i < n; i++) arr[i] += min_ele;
    }
}
