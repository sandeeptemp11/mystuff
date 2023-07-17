// Hollow inverted half pyramid
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n; // n >= 1

    for(int i = n; i >= 1; i--){
        cout << "*";
        for(int j = 2; j <= i - 1; j++){
            if(i == n) cout << "*";
            else cout << " ";
        }
        if(i != 1) cout << "*";
        cout << '\n';
    }
}
