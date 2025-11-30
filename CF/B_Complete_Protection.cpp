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
    int n, m;
    cin >> n >> m;

    vector<int> indeg(n+1, 0);
    vector<vector<int>> Gbi(n+1);
    vector<unordered_set<int>> adj(n + 1);


    while(m--){
        int x,y;
        cin >> x >> y;
        if (adj[y].count(x)) {
            adj[y].erase(x);
            Gbi[x].pb(y);
            Gbi[y].pb(x);
            indeg[x]--;  
        } else {
            adj[x].insert(y);
            indeg[y]++;
        }
    }


    vector<int> ok(n+1, 0);
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] > 0){
            ok[i] = 1;
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto x : Gbi[u]){
            if(!ok[x]){
                ok[x] = 1;
                q.push(x);
            }
        }
    }

    vector<int> vis(n+1, 0);
    for(int i = 1; i <= n; i++){
        if(ok[i] || vis[i]) continue;

        int cntV = 0, degsm = 0;

        queue<int> qq;
        qq.push(i);
        vis[i] = 1;

        while(!qq.empty()){
            int x = qq.front();
            qq.pop();
            cntV++;
            degsm += Gbi[x].size();
            for(int y : Gbi[x]){
                if(!ok[y] && !vis[y]){
                    vis[y] = 1;
                    qq.push(y);
                }
            }
        }

        int cntE = degsm / 2;
        if(cntE < cntV){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES" << nl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
