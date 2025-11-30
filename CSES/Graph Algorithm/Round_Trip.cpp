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

int st = -1, en = -1;

bool dfs(int x, vector<int> &par, vector<bool> &vis, vector<vector<int>> &adj){
    vis[x] = 1;

    for(auto &i : adj[x]){
        if(!vis[i]){
            par[i] = x;
            if(dfs(i,par,vis,adj)) return true;
        }
        else if (par[x] != i) {
            st = x;
            en = i;
            return true;
        }
    }

    return false;
}


void solve(){
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n);
    while(m--){
        int x,y;
        cin >> x >> y;
        x--, y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    vector<int> par(n,-1);
    vector<bool> vis(n,false);

    auto traverse = [&](){
        vector<int> ans;
        int curr = st;
        while(curr != en){
            ans.pb(curr);
            curr = par[curr];
        }
        ans.pb(curr);
        ans.pb(st);

        cout << ans.size() << nl;
        for(auto &i : ans) cout << i+1 << " ";
        cout << nl;
    };


    
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            if(dfs(i,par,vis,adj)){
                traverse();
                return;
            }
        }
    }


    cout << "IMPOSSIBLE" << nl;
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