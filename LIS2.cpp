class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        // time = n^2 approach, space = O(n)
        int n = arr.size();
        vector <int> dp(n, 1);
        // dp[i] = length of LIS where arr[i] is the first element of LIS
        for(int i = n-2; i >= 0; i--){
            for(int j = i + 1; j <= n-1; j++){
                if(arr[j] > arr[i]) dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
