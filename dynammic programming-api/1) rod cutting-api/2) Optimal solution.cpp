#include <iostream>
using namespace std;
void print(int n, const int s[]){
    int i = n;
    int first = s[i];
    cout << first << " ";
    while(first != i){
        i = first;
        first = s[i];
        cout << first << " ";
    }
    cout << "\n";
}
void solve(const int& n, const int p[]){
    int r[1+n]; // r[i] = optimal revenue value for length i
    int s[1+n]; // s[i] = length of the first part of the rod to get optimal value
    r[0] = 0;   // revenue for rod of length 0 is zero

    for(int i = 1; i <= n; i++){
        // no cut
        r[i] = p[i];
        s[i] = i;

        // cuts from 1 to i - 1 first piece
        for(int j = 1; j < i; j++){
            if(r[i] < p[j] + r[i - j]){
                r[i] = p[j] + r[i - j];
                s[i] = j; // first piece j
            }
        }
    }

    cout << "THE OPTIMAL VALUE(max revenue) for length " << n << " is " << r[n] << "\n";
    cout << "ONE OF THE OPTIMAL SOLUTIONS:\n";
    print(n, s);
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
