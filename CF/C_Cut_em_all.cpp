#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dp;


void dfs(int u, int par){
    for(auto &v : adj[u]){
        if(v == par){
            continue;
        }
        dfs(v,u);
        dp[u] += dp[v];
    }
}

void solve(){
    int n;
    cin >> n;

    adj.assign(n,{});
    dp.assign(n,1);
    
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n&1) cout << -1 << endl;
    else{
        dfs(0,-1);
        

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] % 2 == 0) ans++;
        }
        cout << ans-1 << endl;
    }

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