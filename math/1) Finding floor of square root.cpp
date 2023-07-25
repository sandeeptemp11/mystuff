template <typename t> int findsqrt(t& n){ // time: O(logn), space: O(1)
    if(n <= 1) return n;
    int low = 2;
    int high = min((int)1e9, (int)n);

    while(low <= high){
        int mid = (high + low)/2;
        if(mid > n/mid) high = mid - 1;
        else low = mid + 1;
    }
    return low - 1;
}
