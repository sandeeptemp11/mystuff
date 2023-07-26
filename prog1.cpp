#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(long long n){
    string check = to_string(n);
    int i = 0;
    int j = check.size() - 1;
    while(i < j){
        if(check[i] != check[j]) return false;
        i++;
        j--;
    }
    return true;
}

void solve(){
    long long l, r;
    cin >> l >> r;
    long long limit = min((long long)pow(10, 5), r + 1); int c{0};
    for(int i = 1; i < limit; i++){
        string str = to_string(i);
        string rev = str;
        reverse_copy(str.begin(), str.end(), rev.begin());
        
        string str1 = str + rev;
        long long n1 = stoll(str1);
        n1 = n1 * n1;
        if(n1 >= l && n1 <= r && is_palindrome(n1)) c++;
        
        string str2 = str + rev.substr(1, rev.size());
        long long n2 = stoll(str2);
        n2 = n2 * n2;
        if(n2 >= l && n2 <= r && is_palindrome(n2)) c++;
    }
    cout << c << "\n";
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}
