#include <bits/stdc++.h>

// O(sqrt(n)) time
int sumOfAllDivisors(int n){
	int sum = 0;
    int l = 1;
    while(l <= n){
        int k = n/l;
        int r = n/k;

        // from i to l to r we have floor(n/i) = k
        sum += k *(r*(r+1)/2 - (l-1)*l/2);
        l = r + 1;
    }
	return sum;
}

int main(){
  int n;
  cin >> n;
  cout << sumOfAllDivisors(n) << "\n";
}
