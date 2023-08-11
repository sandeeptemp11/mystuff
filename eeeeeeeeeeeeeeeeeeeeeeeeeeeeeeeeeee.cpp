#include <iostream>
#include <set>
using namespace std;

int main(){
    set <int, greater <int>> s;
    for(int i = 1; i <= 10; i++) s.insert(i);
    auto it = s.find(4);
    set <int> s2;
    s2.insert(it, s.end());
    for(auto& ele: s2) cout << ele << "\n";
}
