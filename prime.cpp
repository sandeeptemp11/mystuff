#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n){
	int low = 1;
	int high = n;
	while(low <= high){
		int mid = (low + high)/2;
		if(mid > n/mid) high = mid - 1;
		else low = mid + 1;
	}
	return high;
}

bool isPrime(int n){
	if(n <= 1) return false;
	int mySqrt = floorSqrt(n);
	for(int i = 2; i <= mySqrt; i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	isPrime(n) ? cout << "true" : cout << "false";
}
