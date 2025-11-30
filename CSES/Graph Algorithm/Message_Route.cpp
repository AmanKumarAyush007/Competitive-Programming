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
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    while(m--){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(auto &i : adj){
        debug(i);
        cout << nl;
    }


    vector<bool> vis(n+1);
    vector<int> parent(n+1);

    queue<int> q;
    q.push(1);

    auto traverse = [&](){
        vector<int> ans;
        int curr = n;
        while(curr != 1){
            ans.push_back(curr);
            curr = parent[curr];
        }
        ans.pb(1);

        reverse(all(ans));

        cout << ans.size() << nl;
        for(auto &i : ans) cout << i << " ";
        cout << nl;
    };

    vis[1] = 1;

    while(q.size()){
        int x = q.front();
        q.pop();
        
        for(auto &i : adj[x]) {
            if(!vis[i]) {
                q.push(i);
                parent[i] = x;
                vis[i] = 1;
            }
            if(i == n){
                traverse();
                return;
            }
        }
    }

    cout << "IMPOSSIBLE" << nl;
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