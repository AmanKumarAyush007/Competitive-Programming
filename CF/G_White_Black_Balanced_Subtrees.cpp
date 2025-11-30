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

void dfs(int u, vector<vector<int>> &adj, string &s, vector<pi>& sol){

    for(auto &v : adj[u]){
        dfs(v,adj,s,sol);
        sol[u].ff += sol[v].ff;
        sol[u].ss += sol[v].ss;
    }

    if(s[u] == 'W') sol[u].ff++; 
    else sol[u].ss++;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    int curr = 1;

    for(int i = 0; i < n-1; i++){
        int x;
        cin >> x;
        x--;
        adj[x].pb(curr);
        curr++;
    }


    string s;
    cin >> s;

    vector<pi> sol(n);

    
    dfs(0,adj,s,sol);

    int ans = 0;

    for(auto &[a,b] : sol) if(a==b) ans++;

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