#include<bits/stdc++.h>
using namespace std;

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


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void dfs(vector<vector<int>>& adj,int ngh, int curr, bool out){
    for(auto &x : adj[ngh]){
        if(out) cout << ngh << " " << x << nl;
        if(x == curr) continue;
        dfs(adj,x,ngh,!out);
    }
}


void solve(){
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    bool fnd = false;
    int val = -1;
    
    for(int i = 1; i <= n; i++){
        if(adj[i].size() == 2) fnd = true, val = i;
    }

    if(!fnd) cout << "NO\n";
    else{

        cout << "YES\n";

        cout << val << " "<< adj[val][0] << nl;

        dfs(adj,adj[val][0] , val, false);
        dfs(adj,adj[val][1] , val, true);
        
    }
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