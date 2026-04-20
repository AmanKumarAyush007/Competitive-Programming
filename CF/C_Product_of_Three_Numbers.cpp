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


vector<int> f(int n){
    vector<int> v;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            v.pb(i);
            
            if(i != n/i) v.pb(n/i);
        }
    }
    return v;
}

void solve(){
    int n;
    cin >> n;

    auto v = f(n);

    for(auto &i : v){
        n /= i;
        auto u = f(n);
        for(auto &j : u){
            if(i == j) continue;
            int k = n/j;
            if(k != j && k != i){
                cout << "YES\n";
                cout << i << " " << j << " " << k << nl;
                return;
            }
        }

    }

    cout << "NO" << nl;
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