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
vector<int> depth, mxdepth;

void dfs(int node, int dpt, int par){
    depth[node] = dpt;
    mxdepth[node] = dpt;

    for(auto &x : tree[node]){
        if(x != par){
            dfs(x, dpt + 1, node);
            mxdepth[node] = max(mxdepth[node],mxdepth[x]); 
        }
    }
}

void solve(){
    int n;
    cin >> n;

    tree.assign(n,{});
    depth.assign(n,0);
    mxdepth.assign(n,0);

    for(int i = 0; i < n-1; i++){
        int x,y;
        cin >> x >> y;
        x--, y--;
        tree[x].pb(y);
        tree[y].pb(x);
    }

    dfs(0,0,-1);


    int mx = mxdepth[0];

    vector<int> cnt(mx+1, 0);

    for(int i = 1; i < n; i++){
        cnt[depth[i]]++;
    }

    vector<int> extra = cnt;

    suffixsum(extra);

    prefixsum(cnt);

    vector<int> cntmx(mx+1, 0);
    for(int i = 0; i < n; i++){
        cntmx[mxdepth[i]]++;
    }

    prefixsum(cntmx);

    int ans = inf;

    for(int i = 1; i < mx+1; i++){
        int val = cntmx[i-1];
        if(i + 1 <= mx) val += extra[i+1];
        ans = min(ans,val);
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