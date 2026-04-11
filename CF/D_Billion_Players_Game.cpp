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
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> v(n);
    inp(v);

    sort(all(v));

    int ans = 0;

    vector<int> pre = v;
    vector<int> suff = v;

    prefixsum(pre);
    suffixsum(suff);

    auto f = [&](int x, int i){
        int left = i+1;
        int right = n - (i+1);

        int presm = (i >= 0 ? left*x - pre[i] : 0);
        int suffsm = (i+1 < n ? suff[i+1] - right*x : 0);

        return (presm + suffsm);
    };

    auto g = [&](int x, int i){
        int left = i;
        int right = n - (i+1);

        int presm = (i-1 >= 0 ? left*x - pre[i-1] : 0);
        int suffsm = (i+1 < n ? suff[i+1] - right*x : 0);

        return (presm + suffsm);
    };


    // no zero taken
    for(int i = -1; i < n; i++){
        int val = min(f(l,i), f(r,i));
        ans = max(ans, val);
    }

    //one zero taken
    for(int i = 0; i < n; i++){
        int val = min(g(l,i), g(r,i));
        ans = max(ans, val);
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