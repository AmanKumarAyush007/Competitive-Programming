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

vector<vector<int>> tree;
vector<int> child;
vector<int> level;

void dfs(int x, int par, int lvl){
    level[x] = lvl;
    for(auto &u : tree[x]){
        if(u != par){
            dfs(u,x, lvl+1);
            child[x] += 1 + child[u];
        }
    }
}


void solve(){
    int n, m;
    cin >> n >> m;

    tree.assign(n,{});
    child.assign(n,0);
    level.assign(n,0);
    int ans = 0;

    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    dfs(0,-1, 0);

    vector<int> val;

    for(int i = 0; i < n; i++){
        val.pb(child[i] - level[i]);
    }

    sort(all(val));

    for(int i = m; i < n; i++){
        ans += val[i];
    }

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