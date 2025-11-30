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

    int cnt = 0;
    
    int ind = -1;
    
    ///////////////////////////

    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);

    
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x == 0){
            cnt++;
            ind = i;
        }
        while(x--){
            int u;
            cin >> u;
            adj[u].pb(i);
            indeg[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indeg[i] == 0) q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }

    vector<int> dp(n + 1, 0);
    for (int u : topo) {
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }

    int ans = *max_element(dp.begin(), dp.end()) ;


    ///////////////////



    // debug(adj);


    if(cnt >= 2 || ind ==-1 || ans < n-1) cout << 0;
    else cout << 1;

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