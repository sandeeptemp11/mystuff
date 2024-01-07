#include <bits/stdc++.h>

// void shell_sort(int n, vector <int>& arr){
//     for(int gap = n/2; gap >= 1; gap /= 2){
//         for(int i = gap; i <= n-1; i++){
//             for(int j = i - gap; j >= 0 && arr[j + gap] < arr[j] ; j -= gap){
//                 swap(arr[j+gap], arr[j]);
//             }
//         }
//     }
//     return;
// }

void shell_sort(int n, vector <int>& arr){
    for(int gap = n/2; gap >= 1; gap /= 2){
        for(int i = gap; i <= n-1; i++){
            int key = arr[i];
            int j;
            for(j = i - gap; j >= 0 && key < arr[j] ; j -= gap){
                arr[j + gap] = arr[j]; // this is better than swapping
            }
            arr[j + gap] = key;
        }
    }
    return;
}
