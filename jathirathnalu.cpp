/*
Sub-array cannot be empty
*/
pair <long long, pair<int, int>> kadane(vector <int>& arr, int n){
    long long max_sum = 0;
    int s_max = 0;
    int l_max = -1;
    int max_num = arr[0];
    long long sum = 0;
    int s = 0;
    for(int i = 0; i < n; i++){
        max_num = max(max_num, arr[i]);
        sum += arr[i];
        if(max_sum < sum){
            max_sum = sum;
            s_max = s;
            l_max = i;
        }
        if(sum < 0){
            sum = 0;
            s = i + 1;
        }
    }
    if(l_max == -1) return make_pair(max_num, make_pair(s_max, l_max));
    return make_pair(max_sum, make_pair(s_max, l_max));
}
