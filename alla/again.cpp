#include <iostream>
using namespace std;


void selection_sort(int n, int arr[]){
    int min_index;
    for(int i = 0; i < n - 1; i += 1){
        min_index = i;
        for(int j = i + 1; j < n; j ++){
            if (arr[min_index] > arr[j]){
                min_index = j;
            }
        }
        if(min_index != i){
            // swapping
            arr[min_index] = arr[i] + arr[min_index];
            arr[i] = arr[min_index] - arr[i];
            arr[min_index] = arr[min_index] - arr[i];
        }
    }
    return;
}


int main(){


    while(true){
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of an array:\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    selection_sort(n, arr);
    cout << "Array after sorting:\n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    }
    return 0;
}
