#include <iostream>
using namespace std;

void insertion_sort(int n, int arr[]){
    int j, key;
    for(int i = 1; i < n; i ++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
    return;
}


int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements of the array:\n";
    int arr[n];
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    insertion_sort(n, arr);
  
    cout << "Elements of the array after sorting:\n";
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
   
    return 0;
}
