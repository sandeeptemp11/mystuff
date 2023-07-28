int maxIntervals(int start[], int end[], int n)
{
    pair<int, int> arr[n];
    for(int i = 0; i < n; i++){
        arr[i].first = end[i];
        arr[i].second = start[i];
    }
    sort(arr, arr+n);
    int f = arr[0].first;
    int c = 1;
    for(int i = 1; i < n; i++){
        if(arr[i].second > f){
            f = arr[i].first;
            c++;
        }
    }
    return c;
}
