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
    
    vector<vector<int>> adj(n);
    vector<int> par(n,-1);
    vector<int> dist(n);
    
    for(int i = 0; i < n-1; i++){
        int x,y;
        cin >> x >> y;
        x--, y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vector<vector<int>> nodes(n);

    queue<int> q;
    q.push(0);
    dist[0] = 0;

    while(q.size()){
        int curr = q.front();
        q.pop();
        int depth = dist[curr];

        for(auto &i : adj[curr]){
            if(par[i] == -1 && i){
                dist[i] = depth+1;
                nodes[dist[i]].pb(i);
                par[i] = curr;
                q.push(i);
            }
        }
    }

    vector<int> turn(n);
    turn[0] = 0;

    for(int i = 1; i < n; i++){
        set<int> st;
        int m = nodes[i].size();

        for(int j = 0; j < m+1; j++){
            st.insert(j);
        }

        for(int j = 0; j < m; j++){
            turn[nodes[i][(j+1) % m]] = turn[par[nodes[i][j]]];
            st.erase(turn[par[nodes[i][j]]]);
        }

        for(auto &x : nodes[i]){
            if(turn[x] == turn[par[x]]){
                turn[x] = *st.begin();
                st.erase(st.begin());
            }
        }
    }


    vector<vector<int>> ans(n);

    int mx = 0;

    for(int i = 0; i < n; i++){
        ans[turn[i]].pb(i);
        mx = max(turn[i]+1, mx);
    }

    cout << mx << nl;
    
    for(int i = 0; i < mx; i++){
        cout << ans[i].size() << nl;
        for(auto &x : ans[i]) cout << x + 1 << " ";
    }
    cout << nl;
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