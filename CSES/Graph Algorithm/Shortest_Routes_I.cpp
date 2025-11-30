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


//Dijkstra Algorithm
void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> dis(n,1e18);
    vector<vector<pi>> adj(n);

    priority_queue<pi,vector<pi>, greater<pi>> pq;

    pq.push({0,0});
    dis[0] = 0;

    map<pi,int> fnd;


    while(m--){
        int u,w,v;
        cin >> u >> v >> w;
        u--, v--;
        if(fnd.count({u,v})) w = min(fnd[{u,v}],w);
        
        fnd[{u,v}] = w;

        adj[u].pb({w,v});
    }

    while(pq.size()){
        auto [dist, node] = pq.top();
        pq.pop();
        if (dist > dis[node]) continue; 

        for(auto [wt,edge] : adj[node]){
            if(dis[edge] > wt + dist){
                dis[edge] = wt + dist;
                pq.push({dis[edge],edge});
            }
        }

    }

    for(auto &i : dis) cout << i << " ";

    cout << nl;
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