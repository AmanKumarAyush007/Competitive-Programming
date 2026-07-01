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


int ans,n;
vector<int> a;
vector<vector<int>> tree;
vector<int> subtree;
set<int> perfect;

void precompute(){
    for(int i = 1; i <= 2000; i++){
        perfect.insert(i*i);
    }
}


void dfs(int x, int p){
    subtree[x] = 1;
    for(auto &child : tree[x]){
        if(child == p) continue;
        dfs(child,x);
        subtree[x] += subtree[child];
    }

    if(!perfect.count(a[x])) return;
    
    vector<int> sub;

    sub.pb(1);
    sub.pb(n-subtree[x]);

    for(auto &i : tree[x]){
        if(i == p) continue;
        sub.pb(subtree[i]);
    }
    
    vector<int> pre = sub;
    prefixsum(pre)
    
    for(int i = 1; i < sub.size()-1; i++){
        ans += sub[i] * pre[i-1] * (pre.back() - pre[i]);
    }

}

void solve(){
    cin >> n;
    
    ans = 0;
    a.resize(n);
    tree.assign(n, {});
    subtree.assign(n, 0);

    inp(a);

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    dfs(0,-1);

    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}