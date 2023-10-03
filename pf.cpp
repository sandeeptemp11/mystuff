int floorSqrt(int n){
    int low = 1;
    int high = n;
    int mid;
    while(low <= high){
        mid = (low + high) /2;
        if(mid > n/mid) high = mid-1;
        else low = mid+1;
    }
    return high;
}
