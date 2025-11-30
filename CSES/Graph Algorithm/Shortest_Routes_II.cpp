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


//Floyd Warshall Algorithm
void solve(){
    int n,m,q;
    cin >> n >> m >> q;

    vector<vector<int>> mat(n+5,vector<int>(n+5,1e18));

    for(int i = 1; i <= n; i++) mat[i][i] = 0;

    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        
        mat[u][v] = min(mat[u][v],w);
        mat[v][u] = min(mat[v][u],w);
    }


    for(int via = 1; via <= n; via++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
            }
        }
    }

    while(q--){
        int u,v;
        cin >> u >> v;
        int ans = ((mat[u][v] >= 1e18) ? -1 : mat[u][v]);
        cout << ans << nl;
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