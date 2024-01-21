#include <bits/stdc++.h>

// O(n) time
int sumOfAllDivisors(int n){
	int sum = 0;
	for(int i = 1; i <= n; i++) sum += n/i*i; // contribution of each i to the sum
	return sum;
}

int  main(){
  int n;
  cin >> n;
  cout << sumOfAllDivisors(n) << "\n";
  return 0;
}
