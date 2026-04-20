#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
#define debug(x...)
#endif
#define int              int64_t
#define ff               first
#define ss               second
#define pb               push_back
#define inf              (int)1e18
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());



void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    inp(v);

    set<int> st(all(v));
    vector<int> vv(all(st));

    if(vv == v) {
        cout << "Yes\n";
        return;
    }



    vector<bool> cp(n), sp(n);

    for(int i = 0; i < n; i++){
        if(v[i] >= i) cp[i] = 1;
        else cp[i] = 0;
    }

    for(int i = n-1; i >= 0; i--){
        sp[i] = (v[i] >= (n-1 - i));
    }

    for(int i = 1; i < n; i++){
        cp[i] = cp[i-1] & cp[i];
    }

    for(int i = n-2; i >= 0; i--){
        sp[i] = sp[i+1] & sp[i];
    }



    for(int i = 0; i < n; i++){
        int l = i;
        int r = n - (i+1) - 1;


        if(l == r){
            if(cp[i] && sp[i+1] && (v[i] > l || v[i+1] > r)) {
                cout << "Yes\n";
                return;
            }
        }
        else if(cp[i] && sp[i+1]){
            cout << "Yes\n";
            return;
        }
    }


    cout << "No" << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}