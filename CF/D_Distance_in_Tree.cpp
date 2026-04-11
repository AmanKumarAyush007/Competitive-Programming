#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
#define debug(x...)
#endif
// #define int              int64_t
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

vector<vector<int>> adj;
vector<vector<int>> dp;
int n, k;
long long ans = 0;

void dfs(int x, int par = -1){
    dp[x][0] = 1;

    for(auto neigh : adj[x]){
        if(neigh == par) continue;

        dfs(neigh, x);

        for(int i = 0; i < k; i++){
            ans += (long long) dp[x][k - i - 1] * dp[neigh][i];
        }

        for(int d = 1; d <= k; d++){
            dp[x][d] += dp[neigh][d-1];
        }
    }
}

void solve(){
    cin >> n >> k;

    adj.assign(n, {});
    dp.assign(n+5, vector<int>(k+5, 0));
    
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    dfs(0);

    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}