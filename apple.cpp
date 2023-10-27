#include <iostream>
#include <map>
using namespace std;

int findSubArraySum(long long int arr[], int n, long long int k){
    map <long long int,int> freq; // you may use unordered_map if the sum of elements is not too large
    long long int curr_sum = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        curr_sum += arr[i];
        if(curr_sum == k) count++;
        if(freq.find(curr_sum - k) != freq.end()) count += freq[curr_sum - k];
        freq[curr_sum]++;
    }
    return count;
}

int main(){
    int n;
    cin >> n;

    long long int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    long long int k;
    cin >> k;

    cout << "Number of sub-arrays of sum " << k << " = " << findSubArraySum(arr, n, k) << "\n";
    return 0;
}
