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

using pi = pair<int,int>;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<pi>> adj(n);

    for(int i = 0; i < m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--, b--;
        adj[a].pb({w,b});
        adj[b].pb({w,a});
    }

    vector<int> dist(n, inf);

    dist[0] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    pq.push({dist[0], 0});

    
    while(pq.size()){
        auto [xd, x] = pq.top();
        pq.pop();

        if(xd > dist[x]) continue;

        for(auto [wt, neigh] : adj[x]){
            if(dist[neigh] < dist[x] + wt) continue;

            dist[neigh] = dist[x] + wt;

            pq.push({dist[neigh], neigh});
        }
    }

    if(dist[n-1] == inf){
        cout << -1 << nl;
        return;
    }

    vector<int> path;
    int curr = n-1;


    while(curr != 0){
        path.pb(curr);

        int prev = -1;

        for(auto &[wt, neigh] : adj[curr]){
            if(dist[neigh] + wt == dist[curr]){
                prev = neigh;
                break;
            }
        }

        curr = prev;
    }

    path.pb(0);

    reverse(all(path));

    for(auto &i : path) cout << i+1 << " ";
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