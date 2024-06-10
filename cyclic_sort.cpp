void cyclic_sort(int n, vector <int>& arr){
    for(int cycle_start = 0; cycle_start <= n-2; cycle_start++){
        while(1){
            int pos = cycle_start;
            for(int i = cycle_start + 1; i <= n-1; i++){
                if(arr[i] <  arr[cycle_start]) pos++;
            }
            if(pos == cycle_start) break;
            while(arr[pos] ==  arr[cycle_start]) pos++; 
            swap(arr[cycle_start], arr[pos]);
        }
    }
}
