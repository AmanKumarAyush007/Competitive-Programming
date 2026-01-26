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

vector<int> l, r;
vector<vector<int>> tree;
vector<vector<int>> dp;

void dfs(int x, int par){
    for(auto &child : tree[x]){
        if(child != par){
            dfs(child, x);
            dp[x][0] += max(dp[child][0] + abs(l[x] - l[child]), dp[child][1] + abs(l[x] - r[child]));
            dp[x][1] += max(dp[child][0] + abs(r[x] - l[child]), dp[child][1] + abs(r[x] - r[child]));
        }
    }
}

void solve(){
    int n;
    cin >> n;

    l.assign(n,0);
    r.assign(n,0);
    tree.assign(n,{});
    dp.assign(n,vector<int>(2,0));

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        l[i] = x;
        r[i] = y;
    }

    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    dfs(0,-1);

    cout << max(dp[0][1], dp[0][0]) << nl;
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