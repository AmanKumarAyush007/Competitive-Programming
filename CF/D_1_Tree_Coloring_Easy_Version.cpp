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

vector<vector<int>> adj;
map<int,vector<int>> mp;
vector<int> parent;

void dfs(int dis, int x, int par){
    mp[dis].pb(x);
    parent[x] = par;
    for(auto &i : adj[x]){
        if(i == par) continue;
        dfs(dis+1,i,x);
    }
}

void solve(){
    int n;
    cin >> n;

    adj.assign(n, {});
    parent.assign(n,-1);
    
    for(int i = 0; i < n-1; i++){
        int x,y;
        cin >> x >> y;
        x--, y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    dfs(0,0,-1);
    
    int ans = 0;

    for(auto &[a,b] : mp){
        ans = max(ans,(int)b.size());
    }

    for(auto &[a,b] : mp){
        int x = b.size();
        if(x == ans){
            set<int> st;
            for(auto &j : b){
                st.insert(parent[j]);
            }
            if(st.size() == 1){
                ans++;
                break;
            }
        }
    }

    cout << ans << nl;
    mp.clear();
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