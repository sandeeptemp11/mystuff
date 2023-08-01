// Maximum sum of sub-array of length k
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	
	int arr[n];
	for(int i = 1; i <= n; i++) cin >> arr[i-1];

	if(k == 0){
		cout << "Empty subarray, maximum sum = 0\n";
	}else if(k > n){
		cout << "There exists no such sub-array\n";
	}else{
		int curr_length = 0;
		long long curr_sum = 0;
		long long max_sum = LLONG_MIN;
		int low_index = -1; // zero base
		int high_index = -1; // zero base

		int i = 0;
		int start = 0;
		while(i < n){
			while(i < n && curr_length < k){
				curr_sum += arr[i++];
				curr_length++;
			}
			if(max_sum < curr_sum){
				max_sum = curr_sum;
				low_index = start;
				high_index = i - 1;
			}
			curr_sum -= arr[start++];
			curr_length--;
		}

		cout << "Maximum sub-array sum of length " << k << ": " << max_sum << "\n";
		cout << "Sub-array of maximum sum:\n";
		for(int i = low_index; i <= high_index; i++) cout << arr[i] << " ";
		cout << "\n";
	}
}
