// Counting sort
#include <bits/stdc++.h>
using namespace std;

int normalize(int arr[], int n, int min_ele){
    if(min_ele < 0){
        for(int i = 0; i < n; i++) arr[i] += -min_ele;
        return min_ele;
    }
    return 0;
}

void denormalize(int arr[], int nf, int n){
    if(nf == 0) return;
    for(int i = 0; i < n ; i++) arr[i] += nf;
}

// Space complexity: O(n + k)
// time complexirt: O(n + k)
void counting_sort(int arr[], int n, int k, int base){
    vector <int> count(k+1, 0); // this step is not feasible every time
    for(int i = 0; i <= n-1; i++) count[arr[i]-base]++;
    for(int i = 1; i <= k; i++) count[i] += count[i-1];
    vector <int> ans(n);
    for(int i = n-1; i >= 0; i--) ans[--count[arr[i]-base]] = arr[i]; // loop is runned from the back so that stability is maintained
    copy(ans.begin(), ans.end(), arr);
}

int main(){
    int n; // Number of elements
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int min_ele = *min_element(arr, arr+n);
    int max_ele = *max_element(arr, arr+n);
    int k = max_ele - min_ele;
    int nf = normalize(arr, n, min_ele); // nf -  normalizing factor

    counting_sort(arr, n, k, min_ele + abs(nf));
    denormalize(arr, nf, n);
    cout << "After sorting:\n";
    for(int i = 0; i <= n - 1; i++) cout << arr[i] << " ";
    cout << "\n";
}
