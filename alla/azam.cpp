// Time = O(n^(3/2))
#include <bits/stdc++.h>

int f(int n){
	int up = sqrt(n);
	int sum = 0;
	for(int i = 1; i <= up; i++){
		if(n%i == 0){
			if(i != n/i) sum += n/i;
			sum += i;
		}
	}
	return sum;
}
int sumOfAllDivisors(int n){
	int up = sqrt(n);
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += f(i);
	}
	return sum;
}

int  main(){
  int n;
  cin >> n;
  cout << sumOfAllDivisors(n) << "\n";
  return 0;
}
