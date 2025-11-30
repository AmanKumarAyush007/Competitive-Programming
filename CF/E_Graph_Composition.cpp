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

using pi = pair<int,int>;

struct DSU {
    vector<int> e;

    DSU(int n) : e(n, -1) {}

    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }

    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};


void solve(){
    int n,m1, m2;
    cin >> n >> m1 >> m2;


    set<pi> F,G;


    while(m1--){
        int x,y;
        cin >> x >> y;
        if(x < y) swap(x,y);
        F.insert({x,y});
    }  
    while(m2--){
        int x,y;
        cin >> x >> y;
        if(x < y) swap(x,y);
        G.insert({x,y});
    }

    int ans = 0;

    DSU dsu(n+1);

    for(auto &[x,y] : G) dsu.join(x,y);

    vector<pair<int,int>> keptF;
    for (auto &[u,v] : F) {
        if (dsu.find(u) != dsu.find(v)) ans++; 
        else keptF.push_back({u,v});
    }

    DSU dsuf(n+1);
    for (auto &[u,v] : keptF) dsuf.join(u,v);

    set<int> sf,sg;

    for(int i = 1; i <= n; i++){
        sf.insert(dsuf.find(i));
        sg.insert(dsu.find(i));
    }

    int diff = sf.size() - sg.size();

    cout << ans + diff << nl;
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