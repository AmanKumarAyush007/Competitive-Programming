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

vector<vector<int>> tree;
vector<int> children, dp;
int n;

void dfs(int x, int par = -1){
    vector<int> kids;

    for(auto &child : tree[x]){
        if(child == par) continue;
        dfs(child, x);
        children[x] += 1 + children[child];
        kids.push_back(child);
    }

    int cnt = kids.size();

    if(cnt == 0){
        dp[x] = 0;
    }
    else if(cnt == 1){
        int c = kids[0];
        dp[x] = children[c];
    }
    else{ 
        int a = kids[0];
        int b = kids[1];
        dp[x] = max(dp[a] + children[b], dp[b] + children[a]);
        debug(x, a, b, dp[a] + children[b], dp[b] + children[a]);
    }
}

void solve(){
    cin >> n;
    
    tree.assign(n,{});
    dp.assign(n,0);
    children.assign(n,0);

    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    dfs(0);
    debug(dp);

    cout << dp[0] << nl;
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