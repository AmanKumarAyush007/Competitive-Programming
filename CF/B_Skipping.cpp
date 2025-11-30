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
    int n;
    cin >> n;
    vector<int> a(n), b(n),pre;
    inp(a)
    inp(b)

    pre = a;

    prefixsum(pre);

    vector<vector<pi>> adj(n);
    for(int i = 0; i < n; i++){
        if(i > 0) adj[i].pb({0,i-1});
        adj[i].pb({a[i], b[i] - 1});
    }

    vector<int> dis(n,1e18);

    dis[0] = 0;

    priority_queue<pi,vector<pi>,greater<>> pq;

    pq.push({0,0});

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

    int ans = hell;

    for(int i = 0; i < n; i++){
        ans = max(ans, pre[i] - dis[i]);
    }
    
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