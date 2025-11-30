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

void solve(){
    int n,m,k,st,en;
    cin >> n >> m >> k >> st >> en;
    vector<vector<pi>> adj(n+1);
    while(m--){
        int u,v;
        cin >> u >> v;
        adj[u].pb({1,v});
        adj[v].pb({1,u});
    }
    while(k--){
        int u,v;
        cin >> u >> v;
        adj[u].pb({2,v});
        adj[v].pb({2,u});
    }

    priority_queue<pi,vector<pi>,greater<>> pq;
    vector<int> dist(n+1,1e18);

    dist[st] = 0;
    pq.push({0,st});

    while(pq.size()){
        auto [wt,u] = pq.top();
        pq.pop();

        if(wt > dist[u]) continue;

        for(auto &[w,v] : adj[u]){
            if(w + wt < dist[v]){
                dist[v] = w + wt;
                pq.push({dist[v],v});
            }
        }
    }


    cout << dist[en] << nl;
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