long long maxSubarraySum(vector<int>& arr, int n){
    long long int ans = 0, curr_sum = 0;
    for(auto ele: arr){
        curr_sum + ele > 0 ? curr_sum += ele : curr_sum = 0;
        ans = max(curr_sum, ans);
    }
    return ans;
}
