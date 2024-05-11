  // Approach 1) 
  // time               : O(N^2)
  // Auxillary space    : O(N)  
vector<int> constructLowerArray(int *arr, int n) {
    vector <int> temp;
    vector <int> ans(n, 0);
    for(int i = n-1; i >= 0; i--){
        auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
        int j = it - temp.begin();
        ans[i] = j;
        temp.insert(it, arr[i]);
    }
    return ans;
}
