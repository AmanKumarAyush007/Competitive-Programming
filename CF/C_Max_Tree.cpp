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

vector<vector<int>> adj;
vector<bool> vis;
vector<int> ans;

void dfs(int x){
    vis[x] = 1;
    for(auto &i : adj[x]){
        if(!vis[i]) dfs(i);
    }
    ans.pb(x);
}


void solve(){
    int n;
    cin >> n;
    adj.resize(n+1);
    vis.resize(n+1,false);

    for(int i = 1; i < n; i++){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        if(a > b) adj[y].pb(x);
        else adj[x].pb(y);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }
    
    reverse(all(ans));

    vector<int> sol(n);

    for(int i = 0; i < n; i++){
        sol[ans[i]-1] = i+1;
    }

    for(auto &i : sol) cout << i << " ";
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        ans.clear();
        adj.clear();
        vis.clear();
        solve();
    }
    return 0;
}