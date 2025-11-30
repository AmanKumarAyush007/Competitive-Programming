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
    vector<int> p, r;
    DSU(int n=0) {
        p.resize(n); r.assign(n,0);
        iota(all(p),0);
    }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a), b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

void solve(){
    int n;
    cin >> n;
    map<int,vector<int>> mp;
    
    for(int i=0;i<n;i++){
        int m; cin >> m;
        for(int j=0;j<m;j++){
            int x; cin >> x;
            mp[x].pb(i);
        }
    }

    DSU dsu(n);
    vector<tuple<int,int,int>> ans;

    for(auto &[val,vec] : mp){
        if(vec.size() < 2) continue;
        int base = vec[0];
        for(int k=1;k<(int)vec.size();k++){
            int v = vec[k];
            if(dsu.unite(base,v)){
                ans.pb({base,v,val});
                if((int)ans.size() == n-1) break;
            }
        }
        if((int)ans.size() == n-1) break;
    }

    int root = dsu.find(0);
    for(int i=1;i<n;i++){
        if(dsu.find(i) != root){
            cout << "impossible" << nl;
            return;
        }
    }

    for(auto &[a,b,val] : ans){
        cout << a+1 << " " << b+1 << " " << val << nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
