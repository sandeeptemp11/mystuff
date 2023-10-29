#include <iostream>
#include <vector>
using namespace std;

int findAllSubarraysWithGivenSum(vector <long long int>& arr, int n, const long long int& k){
    long long int curr_sum = 0;
    int count = 0;
    int s = 0;
    for(int i = 0; i < n; i++){
        curr_sum += arr[i];
        while(curr_sum > k) curr_sum -= arr[s++];
        if(curr_sum == k) count++;
    }
    return count;
}

int main(){
    int n;
    cin >> n;

    vector <long long int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    long long int k; // req sum
    cin >> k;

    cout << findAllSubarraysWithGivenSum(arr, n, k) << "\n";
}
