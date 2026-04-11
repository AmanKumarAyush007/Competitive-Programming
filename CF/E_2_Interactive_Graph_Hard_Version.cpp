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
#define nl               endl
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());


vector<vector<int>> paths = {
    {1},
    {1,2},
    {1,2,4},
    {1,2,5},
    {1,3},
    {1,3,4},
    {1,3,5},
    {2},
    {2,4},
    {2,5},
    {3},
    {3,4},
    {3,5},
    {4},
    {5}
};

int k = 1;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> res;
vector<int> dp;

void query(int q){
    cout << "? " << q << nl;
    res = paths[q-1];
    return;
    int sz;
    cin >> sz;
    
    res.resize(sz);
    for(auto &i : res) cin >> i;
}


void dfs(int i, int curr){
    query(curr);
    vis[i] = 1;

    debug(i, curr, res);

    int nxt = -1;

    for(int j = 0; j < res.size(); j++){
        if(res[j] == i){
            if(j+1 >= res.size()) return;
            else nxt = res[j+1];
        }
    }

    debug(nxt);

    if(nxt == -1) return;

    adj[i].pb(nxt);

    if(!vis[nxt]) {
        dfs(nxt, curr+1);
    }

    dp[i] += 1 + dp[nxt];
}


void solve(){
    int n;
    cin >> n;

    adj.assign(n+5, {});
    dp.assign(n+5, 0);
    vis.assign(n+5, false);

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            // cout << "sajisif";
            dfs(i, k+1);
            k += dp[i];
        }
    }


    for(int i = 1; i <= n; i++){
        debug(adj[i]);
    }

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