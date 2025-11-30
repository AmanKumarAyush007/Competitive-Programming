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
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()

void solve(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> g(n+1);
    for(int i=2;i<=n;i++){
        int p; cin >> p;
        g[p].pb(i);
    }

    int z = k, o = n-k;
    int ans = 0;

    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int sz = q.size();
        int cnt = sz;  // nodes at this depth

        // to extend depth, need cnt zeros or cnt ones
        if(z >= cnt || o >= cnt){
            if(z >= cnt && (z >= o || o < cnt)) z -= cnt;
            else o -= cnt;
            ans++;
        }else{
            break;
        }

        while(sz--){
            int u = q.front(); q.pop();
            for(auto v: g[u]) q.push(v);
        }
    }

    cout << ans << nl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
