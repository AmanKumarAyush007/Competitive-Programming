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
#define inf              LLONG_MAX
#define hell             LLONG_MIN
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

    vector<int> a(n+1), b(n+1), pa(n+1,0), pb(n+1,0);

    int xa = 0, xb = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        xa ^= a[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> b[i];
        xb ^= b[i];
    }

    if(xa^xb == 0){
        cout << "Tie\n";
        return;
    }


    for(int i = n; i > 0; i--){
        if(a[i] != b[i]){
            if(i&1) cout << "Ajisai\n";
            else cout << "Mai\n";
            return;
        }
    }

    cout << nl;
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