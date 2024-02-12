#include <bits/stdc++.h> 
// HASH TABLE IS NOT GOOD TO USE
int getLongestSubarray(vector<int>& arr, int k){
    int n = arr.size();
    long long int curr_sum = 0;
    map < long long int, int > freq;
    freq[0] = -1;
    int max_len = 0;
    for(int i = 0; i < n; i++){
        curr_sum += arr[i];
        if(freq.find(curr_sum - k) != freq.end())   max_len = max(max_len, i - freq[curr_sum - k]);
        if(freq.find(curr_sum) == freq.end()) freq[curr_sum] = i; // this will make sure to store smallest index
    }
    return max_len;
}
