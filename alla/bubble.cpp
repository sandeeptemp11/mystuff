#include <iostream>
using namespace std;


void bubble_sort(int n, int arr[]){
    int temp;
    for(int i = n - 1; i >= 1; i --){
        for(int j = 0; j < i; j ++){
            if(arr[j + 1] < arr[j]){
                // swapping
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }


    return;
}


int main(){


    while(true){
    int n;
    cout << "Enter size: ";
    cin >> n;


    cout << "Enter elements of the array:\n";
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    bubble_sort(n, arr);


    cout << "Elements of the array after sorting:\n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    }
    return 0;
}
