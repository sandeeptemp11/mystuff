#define pb push_back
#define ll long long int 

class Solution {
public:
    int minimumDifference(vector<int>& arr) {
        int n = arr.size()/2;
        vector <vector<int>> left(1+n), right(1+n);
        ll limit = (1<< n);
        for(int i = 0; i < limit; i++){
            int temp = i;
            int len = 0;
            int sub_sum1 = 0;
            int sub_sum2 = 0;
            int count = 0;
            while(temp > 0){
                if(temp & 1){
                    sub_sum1 += arr[len];
                    sub_sum2 += arr[n + len];
                    count++;
                }
                len++; temp /= 2;
            }
            left[count].pb(sub_sum1);
            right[count].pb(sub_sum2);
        }
        for(int i = 1; i <= n; i++) sort(right[i].begin(), right[i].end());            
        int diff = INT_MAX;
        int s = accumulate(arr.begin(), arr.end(), 0);
        for(int i = 1; i <= n; i++){
            for(int a: left[i]){
                auto it = lower_bound(right[n-i].begin(), right[n-i].end(), (s-2*a)/2);
                if(it != right[n-i].end()) diff = min(diff, abs(s -2*a -2*(*it)));
                if(it != right[n-i].begin()){
                    it--;
                    diff = min(diff, abs(s -2*a -2*(*it)));
                }
            }
        }
        return diff;
    }
};
