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

vector<vector<int>> g;


pi dfs(int u, int p){
    int sum = 0;
    int ht = 0;

    for(auto &v : g[u]){
        if(v != p){
            pi curr = dfs(v,u);
            ht = max(ht, curr.ff);
            sum += curr.ss;
        }
    }
    sum = max(sum, ht + 1);

    return {ht+1,sum};
}


void solve(){
    int n;
    cin >> n;

    g.assign(n+3,{});

    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        g[x].pb(i);
        g[i].pb(x);
    }

    auto [x,y] = dfs(1,-1);
    
    cout << max(x,y) << nl;
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