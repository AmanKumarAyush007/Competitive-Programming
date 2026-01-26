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


const int mod = 998244353;

void solve(){
    int n;
    cin >> n;

    vector<int> par(n), depth(n);
    for(int i = 1; i < n; i++){
        cin >> par[i];
        par[i]--;
        depth[i] = depth[par[i]] + 1;
    }

    vector<vector<int>> level(n);
    for(int i = 0; i < n; i++){
        level[depth[i]].pb(i);
    }

    vector<int> dp(n);
    dp[0] = 1;

    int prev = 1;
    int ans = 1;

    for(int i = 1; i < n; i++){
        int curr = 0;
        for(auto &x : level[i]){
            dp[x] = prev;
            if(i > 1){
                dp[x] = (dp[x] - dp[par[x]] + mod) % mod;
            }
            curr = (curr + dp[x]) % mod;
        }
        ans = (ans + curr) % mod;
        prev = curr;
    }

    cout << ans % mod << nl;
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