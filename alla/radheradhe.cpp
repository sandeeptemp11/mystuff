#include <bits/stdc++.h>

// good approach    
// O(sqrt(n)) time
int sumOfAllDivisors(int n){
	int sum = 0;
    int up = sqrt(n);
    for(int i = 1; i <= up; i++){
        // i + i + .... i 
        int t1 = (n/i - i + 1)*i;
        
        // (i+1) + ... + (n/i)
        int t2 = (n/i)*(n/i + 1)/2 - i*(i+1)/2;
        
        sum += t1 + t2;
    }
	return sum;
}

int main(){
  int n;
  cin >> n;
  cout << sumOfAllDivisors(n) << "\n"
}
