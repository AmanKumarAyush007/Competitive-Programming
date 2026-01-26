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

struct DSU {
    int n;
    vector<int> parent, sz;
    int components;

    DSU(int n) : n(n), parent(n + 1), sz(n + 1, 1), components(n) {
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);    
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;               

        if (sz[a] < sz[b]) swap(a, b);          

        parent[b] = a;
        sz[a] += sz[b];
        components--;

        return true;
    }

};


void solve(){
    int n, p,q;
    cin >> n >> p >> q;

    DSU dsu(n) ,dsu1(n);

    while(p--){
        int x,y;
        cin >> x >> y;
        dsu.unite(x,y);
    }

    while(q--){
        int x,y;
        cin >> x >> y;
        dsu1.unite(x,y);
    }

    vector<pair<int,int>> vp;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((dsu.find(i) != dsu.find(j)) and (dsu1.find(i) != dsu1.find(j))){
                vp.pb({i,j});
                dsu1.unite(i,j);
                dsu.unite(i,j);
            }
        }
    }

    cout << vp.size() << nl;
    for(auto &[a,b] : vp) cout << a << " " << b << nl;
    
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