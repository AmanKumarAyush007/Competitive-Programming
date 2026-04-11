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

vector<vector<int>> adj;
vector<pair<int,int>> topo;
vector<bool> vis;

void dfs(int x = 0){
    vis[x] = 1;

    for(auto u : adj[x]){
        if(!vis[u]){
            topo.pb({x,u});
            dfs(u);
        }
    }
}


void solve(){
    int n;
    cin >> n;

    adj.resize(n, {});
    vis.resize(n, false);
    topo.clear();

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            bool x = s[j] - '0';
            if(x) adj[i].pb(j);
        }
    }

    dfs();

    // reverse(all(topo));

    debug(topo);

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