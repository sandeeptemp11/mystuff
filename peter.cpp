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
