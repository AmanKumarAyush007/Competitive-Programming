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

void solve(){
    int n; 
    cin >> n;

    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v; 
        cin >> u >> v;
        adj[u].pb(v); 
        adj[v].pb(u);
    }

    vector<int> d(n+1, -1);
    queue<int> q;
    d[1] = 0; 
    q.push(1);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto u : adj[x]){
            if(d[u] == -1){
                d[u] = d[x] + 1;
                q.push(u);
            }
        }
    }


    double ans = 0;
    for(int i = 1; i <= n; i++){
        ans += 1.0 / (d[i] + 1);
    }

    cout << fixed << setprecision(9) << ans << nl;
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
