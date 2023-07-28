/*
Here the sub-array is aloowed to be empty
*/
pair <long long, pair<int, int>> kadane(int arr[], int& n){
    long long max_sum = 0;
    int s_max = 0;
    int l_max = -1;

    long long sum = 0;
    int s = 0;
    for(int i = 0; i < n; i++){
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
    return make_pair(max_sum, make_pair(s_max, l_max));
}
