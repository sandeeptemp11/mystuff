void cyclic_sort(int n, vector <int>& arr){
    int cycle_start = 0;
    while(cycle_start <= n-2){
        int pos = cycle_start;
        for(int i = cycle_start + 1; i <= n-1; i++){
            if(arr[i] <  arr[cycle_start]) pos++;
        }
        if(pos == cycle_start){
            cycle_start++;
            continue;
        }
        while(arr[pos] ==  arr[cycle_start]) pos++; 
        swap(arr[cycle_start], arr[pos]);
    }
}
