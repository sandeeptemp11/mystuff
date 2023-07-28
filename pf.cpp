#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    map<int,int> pf; // prime factors map of frequency
    for(int i = 2; i <= sqrt(n); i++){
        while(n%i == 0){
            pf[i]++;
            n /= i;
        }
    }
    if(n > 1) pf[n]++;

    for(auto it: pf) cout << it.first << " : " << it.second << "\n";
}
