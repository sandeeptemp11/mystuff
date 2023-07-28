/*
Here the sub-array is allowed to be empty
*/
pair <long long, pair<int, int>> kadane(const int arr[], const int& n){
    long long max_sum = 0;
    int s_max = 0;
    int l_max = -1;

    long long sum = 0;
    int s = 0;
    int l = -1;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        l++;
        while(sum < 0){
            sum -= arr[s];
            s++;
        }
        if(max_sum < sum){
            max_sum = sum;
            s_max = s;
            l_max = l;
        }
    }
    return make_pair(max_sum, make_pair(s_max, l_max));
}
