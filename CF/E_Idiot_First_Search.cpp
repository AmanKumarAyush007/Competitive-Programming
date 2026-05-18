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

const int mod = 1e9 + 7;
vector<vector<int>> adj;
vector<int> dp;


void dfs(int node = 1){

    for(auto &i : adj[node]){
        dfs(i);
        dp[node] += (2 + dp[i]) % mod;
        dp[node] %= mod;
    }
}

void rec(int node = 1, int par = 0){
    
    dp[node] += (1 + dp[par]) % mod;
    dp[node] %= mod;

    for(auto &i : adj[node]){
        rec(i, node);
    }
}


void solve(){
    int n;
    cin >> n;

    adj.assign(n+1, {});
    dp.assign(n+1,0);

    adj[0].pb(1);
    for(int i = 1; i <= n; i++){
        int x,y;
        cin >> x >> y;
        
        if(x) adj[i].pb(x);
        if(y) adj[i].pb(y);
    }

    dfs();
    rec();

    for(int i = 1; i <= n; i++){
        cout << dp[i] % mod << " ";
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