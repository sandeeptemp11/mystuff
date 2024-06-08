// GFG approach 
// https://www.geeksforgeeks.org/iterative-merge-sort/

// new learning:
// In C++ you cannot declare 0 sized array !
void merge(vector <int>& arr, int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1];
    int right[n2];
    for(int i = low; i <= mid; i++) left[i-low] = arr[i];
    for(int i = mid + 1; i <= high; i++) right[i-mid-1] = arr[i];
    int i = 0;
    int j = 0;
    int k = low;
    while(i < n1 && j < n2){
        if(left[i] < right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];
}

vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    for(int arr_size = 1; arr_size <= n; arr_size = 2*arr_size){
        for(int low = 0; low <= n-1; low += 2*arr_size){
            int mid = min(n-1, low + arr_size - 1);
            int high = min(n-1, low + 2*arr_size - 1);
            if(mid - low + 1 != 0 && high - mid != 0 ) merge(nums, low, mid, high);
        }
    }
    return nums;
}
