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



struct DSU {
    vector<int> parent, sz;
    int comps;

    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
        comps = n;
    }

    int find(int v) {
        return v == parent[v] ? v : parent[v] = find(parent[v]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        comps--;  
        return true;
    }

};



bool dfs(int x, vector<int> &par, vector<bool> &vis, vector<set<int>> &adj){
    vis[x] = 1;

    for(auto &i : adj[x]){
        if(!vis[i]){
            par[i] = x;
            if(dfs(i,par,vis,adj)) return true;
        }
        else if (par[x] != i) {
            return true;
        }
    }

    return false;
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    DSU dsu(n);

    vector<set<int>> adj(n+1);

    
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        dsu.unite(x,i);
        adj[i].insert(x);
        adj[x].insert(i);
    }

    vector<int> par(n+1,-1);
    vector<bool> vis(n+1,false);

    int mn = 1;

    for(int i = 1; i <= n; i++){
        if(!vis[i] && dfs(i,par,vis,adj)) mn++; 
    }

    cout << min(dsu.comps,mn) << " " << dsu.comps;

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