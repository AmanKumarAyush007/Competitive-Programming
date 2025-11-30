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
    vector<int> a(n), b(n);
    inp(a);
    inp(b);

    auto check = [&](int x){
        vector<int> c,d;
        for(int i = 0; i < n; i++){
            int p = a[i] & x;
            int q = (~b[i]) & x;
            c.pb(p);
            d.pb(q);
        }
        sort(all(c));
        sort(all(d));

        return (c == d);
    };

    int ans = 0;

    for(int i = 29; i >= 0; i--){
        if(check(ans | (1LL << i))) ans |= (1LL << i);
    }

    cout << ans << nl;
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