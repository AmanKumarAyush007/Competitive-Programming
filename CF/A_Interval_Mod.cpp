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
    int n,k,p,q;
    cin >> n >> k >> p >> q;

    vector<int> v(n);
    inp(v)

    vector<int> best(n), a(n), b(n);

    for(int i = 0; i < n; i++){
        a[i] = (v[i]%q)%p;
        b[i] = (v[i])%p;
        best[i] = min(a[i], b[i]);
    }

    prefixsum(best);
    prefixsum(a);
    prefixsum(b);


    int ans = inf;

    for(int i = 0; i+k-1 < n; i++){
        int st = i;
        int en = i+k-1;
        
        int def = min(a[en] - (st-1 >= 0 ? a[st-1] : 0), b[en] - (st-1 >= 0 ? b[st-1] : 0));

        int l = 0, r = 0;
        if(st-1 >= 0) l = (st-1 >= 0 ? best[st-1] : 0);
        if(en+1 < n) r = best[n-1] - best[en];

        ans = min(ans, def+l+r);
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