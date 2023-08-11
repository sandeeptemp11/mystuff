int getPairsCount(int arr[], int n, int k) {
    map<int, int> freq;
    int ans = 0;
    for(int i = 0; i < n; i++) freq[arr[i]]++;
    auto it = freq.begin();
    while(it != freq.end()){
        auto loc = freq.find(k - it->first);
        if(loc == it) ans += it->second * (it->second - 1);
        else if(loc != freq.end()) ans += it->second * loc->second;
        it++;
    }
    return ans/2;
}
