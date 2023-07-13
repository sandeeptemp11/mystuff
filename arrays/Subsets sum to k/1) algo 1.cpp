
#include <iostream>
#include <vector>
using namespace std;

/***
You need to save all the subsets in the 2-D vector.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
// time complexity: O(2^(n))
// auxilarry recursive space O(2^(n))
int f(int& row, int k, vector <vector<int>>& output, int arr[], int& n, int i, vector <int> indices){
	if(k == 0){
        output.push_back(vector <int>(indices.size() + 1, 0));
		output[row][0] = indices.size();
		int j = 1;
		for(auto ele : indices){
			output[row][j] = arr[ele];
			j++;
		}
		row++;
		return 1;
	}
	if(i >= n) return 0;
	int count = f(row, k, output, arr, n, i + 1, indices);
	if(arr[i] <= k){
		indices.push_back(i);
		count += f(row, k - arr[i], output, arr, n, i + 1, indices);
	}
	return count;
}

void printSubsets(vector <vector<int>> output){
    auto it = output.begin();
    while(it != output.end()){
        auto itt = (*it).begin();
        itt++;
        while(itt != (*it).end()){
            cout << *itt << " ";
            itt++;
        }
        cout << endl;
        it++;
    }
}

int main(){
    int n; // size of the array
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int k;
    cin >> k; // sum
    
    vector <vector <int>> output(0, vector <int>(0));
    int row = 0;
    int count = f(row, k, output, arr, n, 0, vector <int>(0));
    cout << "Number of subsets: " << count << "\n";
    if(count == 0) return 0;
    cout << "The sum which sum to " << k << " are:\n";
    printSubsets(output);
}
