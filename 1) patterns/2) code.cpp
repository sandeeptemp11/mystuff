// HOllow rectangle
#include <iostream>
using namespace std;
// m >= 1 n >= 1
int main(){
    int m, n;
    cin >> m >> n;

    for(int i = 1; i <= m; i++){
        cout << "* ";
        for(int j = 2; j <= n-1; j++){
            if(i == 1 || i == m) cout << "* ";
            else cout << "  ";
        }
        if(n != 1) cout << "*";
        cout << "\n"; 
    }

}
