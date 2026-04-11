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

vector<int> col;
vector<bool> vis;
vector<vector<int>> adj;

int c1 = 0, c2 = 0;

bool bipart(int x, int color = 1){
    vis[x] = 1;
    col[x] = color;
    
    if(color) c1++;
    else c2++;

    bool res = true;

    for(auto u : adj[x]){
        if(!vis[u]){
            if(!bipart(u, !color)) res = false;
        }
        else if(col[u] == col[x]) res = false;
    }

    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;

    col.assign(n, -1);
    vis.assign(n, 0);
    adj.assign(n, {});

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        c1 = 0, c2 = 0;
        if(!vis[i] && bipart(i)){
            ans += max(c1,c2);
        }
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