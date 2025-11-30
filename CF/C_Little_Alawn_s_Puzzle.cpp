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


const int mod = 1e9+7;

int binpow(int x){
    if(x == 0) return 1;
    if(x == 1) return 2;

    int curr = binpow(x/2) % mod;

    int val = (curr*curr)%mod;

    if(x&1) return (val*2)%mod;
    else return val;
}

vector<vector<int>> graph(4e5+5);
vector<bool> vis(4e5+5);

void dfs(int x){
    vis[x] = 1;
    for(auto &i : graph[x]){
        if(!vis[i]) dfs(i);
    }
}


void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    inp(a)
    inp(b)

    graph.assign(n,{});
    vis.assign(n,false);

    for(int i = 0; i < n; i++){
        int u = a[i], v = b[i];
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }


    int x = 0;

    for(int i = 0; i < n; i++){
        if(!vis[i]) {
            x++;
            dfs(i);
        }
    }
    cout << binpow(x) << nl;
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