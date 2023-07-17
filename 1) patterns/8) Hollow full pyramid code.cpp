// Hollow full pyramid
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n; // n >= 1
    for(int i = n; i >= 1; i--){
        for(int j = 1; j < i; j++) cout << " ";
        cout << "*";
        for(int j = 2; j <= 2*(n - i + 1) - 1 - 1; j++){
            if(i == 1){
                if(j%2) cout << "*";
                else cout << " ";
            }else cout << " ";
        }
        if(i != n) cout << "*";
        cout << "\n";
    }
}
