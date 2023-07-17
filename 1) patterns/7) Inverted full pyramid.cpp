// Inverted full pyramid
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n; // n >= 1
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++) cout << " ";
        for(int j = 1; j <= 2*(n - i + 1) - 1; j++){
            if(j % 2) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}
