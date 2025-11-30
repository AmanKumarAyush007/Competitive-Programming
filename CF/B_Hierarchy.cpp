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

using pi = pair<int,int>;

vector<int> topo;

void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj){
    vis[u] = 1;

    for(auto &v : adj[u]){
        if(!vis[v]) dfs(v,vis,adj);
    }

    topo.pb(u);
}

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    inp(v);

    int m;
    cin >> m;

    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    map<int,int> cost;

    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].pb(v);
        if(cost.count(u)) cost[u] = min(cost[u],v);
        else cost[u] = v;
    }

    for(int i = 0; i < n; i++){
        if(!vis[i]) dfs(i,vis,adj);
    }

    reverse(all(topo));

    for(auto &i : topo) i++;

    debug(topo);

    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        topo.clear();
        solve();
    }
    return 0;
}