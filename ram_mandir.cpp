long long maxSubarraySum(vector<int>& arr, int n){
    long long int ans = 0, curr_sum = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        // the below while loop is not required because every time we subtract a part which is always <= 0, implies curr_sum - that part >= curr_sum
        // good observation
        while (j < i && curr_sum + arr[i] < 0){
            curr_sum -= arr[j++];
            ans = max(curr_sum, ans);
        }
        if(curr_sum + arr[i] >= 0) curr_sum += arr[i];
        else j++;
        ans = max(curr_sum, ans);
    }
    // the below while loop is not required because every time we subtract a part which is always <= 0, implies curr_sum - that part >= curr_sum
    while (j < n){
        curr_sum -= arr[j++];
        ans = max(curr_sum, ans);
    }
    return ans;
}
