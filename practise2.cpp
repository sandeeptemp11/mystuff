class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& arr) {
        
        // // my approach
        // vector <int> ans(n, -1);
        // stack <int> s;
        // for(int i = n-2; i >= 0; i--) s.push(arr[i]);
        // for(int i = n-1; i >= 0; i--){
        //     while(!s.empty() && s.top() <= arr[i]) s.pop();
        //     if(!s.empty()) ans[i] = s.top();
        //     s.push(arr[i]);
        // }
        // return ans;
        
        // another nice approach:
        vector<int> ans(n, -1);
        stack<int> s;
        for (int i = 0; i < 2 * n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i % n]) {
                ans[s.top()] = arr[i % n];
                s.pop();
            }
            if (i < n)
                s.push(i);
        }
        return ans;
        
    }
};
