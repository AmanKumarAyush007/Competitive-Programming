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

const int mod = 676767677;

void solve(){
    int n,m;
    cin >> n >> m;

    vector<int> v(n);
    inp(v);

    map<int,int> mp, f;
    for(auto &i : v) {
        mp[i+1]++;
        f[i]++;
    }

    int ans = 1;

    for(int i = 1; i <= n; i++){
        mp[i] += mp[i-1];
    }

    for(int i = 0; i < n; i++){
        if(v[i] == 0) continue;

        int t = v[i];
        int mn = 1e9;

        if(i+1 < n) mn = min(v[i+1],mn);
        if(i-1 >= 0) mn = min(v[i-1],mn);

        if(mn >= t) {
            ans = 0;
            break;
        }
        else if(mn == t-1) ans = (mp[t]*ans)%mod;
        else ans = ((f[t-1])*ans)%mod;
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