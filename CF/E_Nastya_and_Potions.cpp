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


map<int,int> check;

int rec(int x,vector<int> &dp,vector<vector<int>>& adj, vector<int>& cost){
    if(adj[x].size() == 0) {
        return cost[x];
    }

    if(check.count(x)) return dp[x];

    int cst = 0;
    for(auto &i : adj[x]){
        cst += rec(i,dp,adj,cost);
    }

    check[x]++;

    cost[x] = min(cst,cost[x]);

    return dp[x] = min(cst,cost[x]);
}

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> cost(n), own(k);
    inp(cost);
    inp(own);

    for(auto &i : own) cost[i-1] = 0;

    vector<vector<int>> adj(n);
    vector<int> dp(n,1e10);

    
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            adj[i].pb(x-1);
        }
    }


    for(int i = 0; i < n; i++){
        cout << rec(i,dp,adj,cost) << " ";
    }

    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        check.clear();
        solve();
    }
    return 0;
}