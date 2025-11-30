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
vector<bool> bipart(2e5+5);
vector<pair<int,int>> val(2e5+5);
vector<int> parent(2e5+5);

void dfs(int par,int x = 1){
    parent[x] = par;
    for(auto &y : tree[x]){
        if(y != par){
            bipart[y] = !bipart[x];
            dfs(x,y);
        }
    }
}

void compute(vector<int> &v,int par,int x = 1){
    if(x != 1) {
        if(bipart[x]) val[x].ff = val[par].ff - val[x].ff, val[x].ss = val[par].ss - val[x].ss;
        else val[x].ff += val[par].ff, val[x].ss += val[par].ss;
    }
    for(auto &y : tree[x]){
        if(y != par){
            compute(v,x,y);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    tree.assign(n+1,{});

    for(int i = 0; i < n; i++){
        val[i+1].ff = v[i];
        val[i+1].ss = -v[i];
    }

    for(int i = 0; i < n-1; i++){
        int x,y;
        cin >> x >> y;
        tree[y].pb(x);
        tree[x].pb(y);
    }

    dfs(-1);
    compute(v,-1);

    // for(int i = 1; i <= n; i++){
    //     cout << bipart[i] << " ";
    //     cout << i << " -> ";
    //     cout << val[i].ff << " " << val[i].ss << nl;
    // }

    


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