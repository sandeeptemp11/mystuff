class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        // time = nlogn approach
        // tricky to come up, easy to implement
        // I think by this solution, we cannot get optimal solution, but we can get optimal value
        int n = arr.size();
        vector <int> q;
        q.push_back(arr[0]);
        for(int i = 1; i < n; i++){
            auto it = lower_bound(q.begin(), q.end(), arr[i]);
            if(it == q.end()) q.push_back(arr[i]);
            else *it = arr[i];
        }
        return q.size();
    }
};
