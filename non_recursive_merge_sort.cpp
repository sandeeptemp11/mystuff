struct data{
    int low;
    int high;
    bool left;
    bool right;

    data(int low, int high){
        this->low = low;
        this->high = high;
        this->left = false;
        this->right = false;
    }
};

void merge(vector <int>& arr, int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1];
    int right[n2];
    for(int i = low; i <= mid; i++) left[i-low] = arr[i];
    for(int i = mid + 1; i <= high; i++) right[i-mid-1] = arr[i];
    int i = 0;
    int j = 0;
    int k = low;
    while(i < n1 && j < n2){
        if(left[i] < right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];
}

vector<int> sortArray(vector<int>& nums) {
    stack <struct data> s;
    struct data initial(0, nums.size() - 1);
    s.push(initial);
    while(!s.empty()){
        struct data top = s.top();
        if(top.low == top.high){
            s.pop();
        }else if(top.left == false){
            struct data left_side(s.top().low, (s.top().low + s.top().high)/2);
            s.top().left = true;
            s.push(left_side);
        }else if(top.right == false){
            struct data right_side((s.top().low + s.top().high)/2 + 1, s.top().high);
            s.top().right = true;
            s.push(right_side);
        }else{
            merge(nums, s.top().low, (s.top().low + s.top().high)/2, s.top().high);
            s.pop();
        }
    }
    return nums;
}
