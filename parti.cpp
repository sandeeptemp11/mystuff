int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = low + 1;
    while(j <= high){
        if(arr[j] < pivot) swap(arr[i++], arr[j]);
        j++;
    }
    swap(arr[low], arr[i-1]);
    return i - 1;
}
