// palindrome pattern
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n; // n >= 1

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++) cout << char(65 + j) << " ";
        for(int j = i - 2; j >= 0; j--) cout << char(65 + j) << " ";
        cout << "\n";
    }
}
