int partitionArray(int arr[], int p, int r){
	int pivot = p;
	int key = arr[p];
	int low = p+1;
	for(int i = p + 1; i <= r; i++){
		if(arr[i] < key) swap(arr[i], arr[low++]);
	}
	swap(arr[low-1], arr[pivot]);
	return low-1;
}

void quickSort(int arr[], int p, int r) {
	if(p < r){
		int q = partitionArray(arr, p, r);
		quickSort(arr, p, q);
		quickSort(arr, q+1, r);
	}
	return;
}
