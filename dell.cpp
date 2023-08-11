int partition(int arr[], int low, int high){
    int i = high - 1, j = high-1;
    while(j >= low){
        if(arr[j] > arr[high]) swap(arr[i--], arr[j]);
        j--;
    }
    swap(arr[high], arr[++i]);
    return i;
}
