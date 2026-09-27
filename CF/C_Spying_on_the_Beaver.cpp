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


int n,m;
vector<int> ans,par,a,depth;
vector<vector<int>> adj;

void dfs(int x = 1, int d = 0){
    depth[x] = d;
    for(auto &child : adj[x]){
        if(child != par[x]){
            dfs(child,d+1);
        }
    }
}

void solve(){
    cin >> n;
    par.resize(n+1);
    depth.resize(n+1);
    adj.assign(n+1,{});
    for(int i = 2; i <= n; i++){
        cin >> par[i];
        adj[i].pb(par[i]);
        adj[par[i]].pb(i);
    }
    cin >> m;
    a.resize(m);
    inp(a);

    ans.clear();   

    dfs();

    vector<pair<int,int>> vp;

    for(auto &i : a){
        vp.pb({depth[i],i});
    }

    sort(all(vp));

    cout << m-1 << " ";
    for(int i = 1; i < vp.size(); i++){
        cout << vp[i].ss << " ";
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