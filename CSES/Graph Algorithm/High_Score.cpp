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

struct inp
{
    int u,v,w;
};


//Bellman Ford Algorithm

void solve(){
    int n,m;
    cin >> n >> m;

    vector<int> dist(n,1e18);
    vector<inp> wt(m);
    
    dist[0] = 0;

    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;

        wt[i].u = u;
        wt[i].v = v;
        wt[i].w = -w;
    }


    for(int i = 0; i < n-1; i++){
        for(auto &it : wt){
            int u = it.u;
            int v = it.v;
            int w = it.w;

            if(dist[u] != 1e18) dist[v] = min(dist[v],dist[u] + w);
        }
    }

    
    vector<int> affected(n, 0);
    for (auto &it : wt) {
        if (dist[it.u] != 1e18 && dist[it.u] + it.w < dist[it.v]) {
            affected[it.v] = 1;
        }
    }

    vector<vector<int>> g(n);
    for (auto &it : wt) g[it.u].push_back(it.v);

    queue<int> q;
    for (int i = 0; i < n; i++) if (affected[i]) q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!affected[v]) {
                affected[v] = 1;
                q.push(v);
            }
        }
    }

    if (affected[n - 1]) {
        cout << -1 << nl;
        return;
    }

    cout << -dist[n - 1] << nl;
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