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
    vector<vector<int>> adj(n);
    vector<int> col(n,-1);

    while(m--){
        int x,y;
        cin >> x >> y;
        x--, y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    queue<int> q;

    auto bfs = [&](int x){
        q.push(x);
        col[x] = 0;

        while(q.size()){
            int v = q.front();
            q.pop();

            for(auto &u : adj[v]){
                if(col[u] == -1){
                    col[u] = col[v] ^ 1;
                    q.push(u);
                }
                else if(col[u] != (col[v]^1)){
                    cout << "IMPOSSIBLE\n";
                    return 1;
                }
            }
        }

        return 0;
    };

    for(int i = 0; i < n; i++){
        if(col[i] == -1) {
            if(bfs(i)) return;
        }
    }

    for(auto &i : col) cout << i+1 << " ";
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