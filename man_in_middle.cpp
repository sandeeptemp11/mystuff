#define pb push_back
class Solution {
public:
    int minAbsDifference(vector<int>& arr, int s) {
        int n = arr.size();

        // edge case
        if(n == 1) return min(abs(arr[0] - s), abs(s));
        
        int l = n/2;
        int r = n/2 + (n & 1);
        int m = (1 << l);
        vector <int> s1, s2;
        // all left sums: O(2^N/2)
        for(int i = 0; i < m; i++){
            int temp = i;
            int sum = 0;
            int len = 0;
            while(temp > 0){
                if(temp & 1) sum += arr[len];
                len++;
                temp /= 2;
            }
            s1.pb(sum);
        }
        // all right sums: O(2^(N/2))
        m = (1 << r);
        for(int i = 0; i < m; i++){
            int temp = i;
            int sum = 0;
            int len = 0;
            while(temp > 0){
                if(temp & 1) sum += arr[len + l];
                len++;
                temp /= 2;
            }
            s2.pb(sum);
        }
        // sorting : O(2^(N/2) log(2^N/2)) = O((N/2) * 2^(N/2) )
        sort(s1.begin(), s1.end());
        // sorting : O(2^(N/2) log(2^N/2)) = O((N/2) * 2^(N/2) )
        sort(s2.begin(), s2.end());
        int ans = abs(s);
        //  O(2^(N/2) log(2^N/2)) = O((N/2) * 2^(N/2) )
        for(auto a: s1){
            auto it = lower_bound(s2.begin(), s2.end(), s-a);
            if(it != s2.end()) ans = min(ans, abs(s - (a + *it)));
            if(it != s2.begin()){
                it--;
                ans = min(ans, abs(s - (a + *it)));
            }
        }
        
        return ans;
    }
};
