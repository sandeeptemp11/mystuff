/*
problem:
inut: n
n is the length of the rod
the rod can be cut into any number of pieces to integer parts
array p given which has price
p[i] = price of the rod of length i

output: find the maximum price of among all possible cuts of rod of length n
*/

#include <iostream>
#include <climits>
using namespace std;


// time: 1 + 2 + 3 + 4 + .. + n
// time: n(n+1) / 2
// auxilary space: O(n + 1)
int solve1(const int& n, const int p[]){
    int r[1+n]; // r[i] = maximum revenue obtained of length i
    r[0] = 0;
    for(int i = 1; i <= n; i++){
        r[i] = p[i];
        for(int j = 1; j < i; j++) r[i] = max(r[i], r[j] + r[i - j]); // i - 1 steps 
    }

    return r[n];
}

// time: 1/2 + 2/2 + 3/2 + 4/2 + .. + n/2
// time: n(n+1) / 4
// auxilary space: O(1)
int solve2(const int& n, int p[]){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i/2 + 1; j++) p[i] = max(p[i], p[j] + p[i - j]); // i/2 steps
    }
    return p[n];
}


// time: 1 + 2 + 3 + 4 + .. + n
// time: n(n+1) / 2
// auxilary space: O(n + 1)
int solve3(const int& n, const int p[]){
    int r[1+n]; // r[i] = maximum revenue obtained of length i
    r[0] = 0;
    for(int i = 1; i <= n; i++){
        r[i] = p[i]; // no cut
        for(int j = 1; j < i; j++) r[i] = max(r[i], p[j] + r[i - j]); // i - 1 steps 
    }

    return r[n];  
}

// The following program time: 2 power n.
int solve3recursive(int n, int p[]){
    if(n == 0) return 0;
    int r = INT_MIN;
    for(int i = 1; i <= n; i++) r = max(r, p[i] + solve3recursive(n - i, p));
    return r;
}

void solve(const int& n, int p[]){
    cout << "Algo1: " << solve1(n, p) << ",";
    cout << "Algo2: " << solve2(n, p) << ",";
    cout << "Algo3: " << solve3(n, p) << "\n\n";
}

int main(){
    int n;
    cout << "Enter length of the rod: ";
    cin >> n;

    int p[1+n];
    cout << "Enter prices:\n";
    p[0] = 0; // price of rod length is zero
    
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }

    solve(n, p);
}

/*
input1:
4
1 5 8 9 10 17 17 20 24 30
see picture

optimal value: 10
optimal solution: 2 2
*/
