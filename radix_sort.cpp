// stability of counting sort makes radix sort to work
void counting_sort(vector <int>& arr, int n, int divide_by){
    vector <int> freq(10, 0);
    for(int i = 0; i < n; i++) freq[(arr[i]/divide_by) % 10]++;
    for(int i = 1; i < 10; i++) freq[i] += freq[i-1];

    vector <int> copy_arr(arr.begin(), arr.end());
    
    // the stability of counting sort is mainited by reversely traversing the array in the below loop
    for(int i = n-1; i >= 0; i--) arr[--freq[(copy_arr[i]/divide_by) % 10]] = copy_arr[i];
}

void radix_sort(vector <int>& arr, int n){
    // arr[i] >= 0 for all 0 <= i <= n-1
    int max_ele = *max_element(arr.begin(), arr.end());

    int divide_by = 1;
    while(max_ele > 0){
        counting_sort(arr, n, divide_by);
        max_ele /= 10;
        divide_by *= 10;
    }
}

void sort_arr(vector <int>& arr, int n){
    int min_ele = *min_element(arr.begin(), arr.end());
    if(min_ele < 0){
        for(int i = 0; i < n; i++) arr[i] += -1*min_ele;
    }
    radix_sort(arr, n);
    if(min_ele < 0){
        for(int i = 0; i < n; i++) arr[i] += min_ele;
    }
}
