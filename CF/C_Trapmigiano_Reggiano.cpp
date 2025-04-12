#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x
#define sm(v)      accumulate(all(v),0LL)

vector<bool> visited;

void dfs(vector<vector<int>>& adj, int n){
    visited[n] = true;
    for(auto ele : adj[n]){
        if(!visited[ele]) dfs(adj,ele);
    }
    cout << n << " ";
}

void solve(){
    int n, st, en;
    cin >> n >> st >> en;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited.assign(n+1,false);
    dfs(adj,en);
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