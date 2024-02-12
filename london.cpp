// Two pointer approach
int longestSubarrayWithSumK(vector<int>& arr, long long k) {
    int n = arr.size();
    long long int i = 0, j = 0;
    long long int sum = 0;
    long long int len = 0;
    while(j < n){
        while(i < j && sum + arr[j] > k) sum -= arr[i++];
        if(sum + arr[j] <= k){
            sum += arr[j++];
            if(sum == k) len = max(len, j-i);
        }else{
            // here sum = 0
            i++;
            j++;
        }
    }
    return len;
}
