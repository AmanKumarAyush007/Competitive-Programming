#include<bits/stdc++.h>
using namespace std;

int dp[200005][2];
vector<vector<int>> tree;

void dfs(int src, int par){

    for(auto &child : tree[src]){
        if(child != par){
            dfs(child,src);
            dp[src][0] += max(dp[child][0],dp[child][1]);
        }
    }

    for(auto &child : tree[src]){
        if(child != par){
            int opt = 1 + dp[child][0] + dp[src][0] - max(dp[child][0],dp[child][1]);
            dp[src][1] = max(dp[src][1], opt);
        }
    }

}


void solve(){
    int n;
    cin >> n;

    tree.assign(n+1,{});

    for(int i = 0 ; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1,-1);
    
    cout << max(dp[1][0],dp[1][1]) << endl;
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