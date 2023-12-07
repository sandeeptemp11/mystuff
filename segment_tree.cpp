#include <bits/stdc++.h>
using namespace std;
#define ll long long int
/*
Input format:
n
array of size n
q
q queries each of type 1 (or) 2

1 i new_val (update)
2 L R       (query)
*/
class segment_tree{
    ll n;
    ll* arr;
    ll build_tree(ll low, ll high, ll i);
    ll update_tree(ll low, ll high, ll index, ll val, ll j);
    ll get_sum(ll low, ll high, ll j, ll L, ll R);
    public:
    segment_tree(int n){
        this->n = n;
        arr = new ll[4*n];
        build_tree(0, n-1, 0);
    }
    bool update(ll i, ll val){
        if(i < 1 || i > n) return false;
        update_tree(0, n-1, i-1, val, 0);
        return true;
    }
    ll query(ll L, ll R){
        return get_sum(0, n-1, 0, L-1, R-1);
    }
};

ll segment_tree::build_tree(ll low, ll high, ll i){
    if(low == high) cin >> arr[i];
    else arr[i] = build_tree(low, (low+high)/2, 2*i+1) + build_tree((low+high)/2 + 1, high, 2*i+2);
    return arr[i];
}

ll segment_tree::update_tree(ll low, ll high, ll index, ll val, ll j){
    if(low == high){
        ll old_val = arr[j];
        arr[j] = val;
        return val - old_val;
    }
    ll mid = (low + high)/2;
    ll add_val;
    if(index <= mid) add_val = update_tree(low, mid, index, val, 2*j + 1);
    else add_val = update_tree(mid+1, high, index, val, 2*j + 2);
    arr[j] += add_val;
    return add_val;
}

ll segment_tree::get_sum(ll low, ll high, ll j, ll L, ll R){
    if(low == L && high == R) return arr[j];
    ll mid = (low + high) / 2;
    if(R <= mid) return get_sum(low, mid, 2*j+1, L, R);
    else if(L <= mid) return get_sum(low, mid, 2*j + 1, L, mid) + get_sum(mid+1, high, 2*j+2, mid+1, R);
    return get_sum(mid+1, high, 2*j+2, L, R);
}
int main(){
    int n;
    cin >> n;
    segment_tree data(n);
    ll q, k;
    cin >> q;
    ll i, val, L, R;
    while(q--){
        cin >> k;
        if(k == 1){
            cin >> i >> val;
            data.update(i, val);
        }else{
            cin >> L >> R;
            cout << data.query(L, R) << "\n";
        }
    }
}
