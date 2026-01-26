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
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    inp(v);

    vector<int> pre;

    for(int i = 0; i < n; i++){
        pre.pb(v[i] - k);
    }

    prefixsum(pre);

    int ans = 0;

    for(int i = 0; i < n; i++){
        int curr = (i > 0 ? pre[i-1] : 0);
        int p = 1;
        for(int j = i; j < n; j++){
            if(p >= 32) break;
            int inc = (1LL << p);
            curr += v[j]/inc;
            p++;
        }

        ans = max(curr, ans);
    }

    ans = max(ans,pre[n-1]);

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