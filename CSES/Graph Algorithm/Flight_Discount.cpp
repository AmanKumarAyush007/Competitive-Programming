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

//Dijkstra with state

void solve(){
    int n,m;
    cin >> n >> m;

    vector<set<pi>> adj(n);
    map<pi,int> mp;

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<>> pq;

    vector<vector<int>> dist(n,vector<int>(2,1e18));

    while (m--){
        int u,v,w;
        cin >> u >> v >> w;
        u--, v--;

        if(mp.count({u,v})) w = min(mp[{u,v}],w);
        mp[{u,v}] = w;

        adj[u].insert({w,v});
    }

    dist[0][0] = dist[0][1] = 0;

    pq.push({0,0,0});

    while(pq.size()){
        auto [wt,u, used] = pq.top();
        pq.pop();

        if(wt > dist[u][used]) continue;

        for(auto &[w,v] : adj[u]){
            if(used == 0){
                if(wt + w < dist[v][0]){
                    dist[v][0] = wt + w ;
                    pq.push({dist[v][0],v,0});
                }

                if(wt + w/2 < dist[v][1]){
                    dist[v][1] = wt + w/2 ;
                    pq.push({dist[v][1],v,1});
                }
            }
            else{
                if(wt + w < dist[v][1]){
                    dist[v][1] = wt + w;
                    pq.push({dist[v][1],v,1});
                }
            }
        }
    }
    
    cout << dist[n-1][1] << nl;
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