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
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<int,int>> vp(n);
    
    for(int i = 0; i < n; i++){
        cin >> vp[i].ff;
        cin >> vp[i].ss;
    }
    
    map<int,vector<int>> po;
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        po[x].pb(y);
    }
    
    int jmp = 1;
    int ans = 0;

    priority_queue<int> pq;
    for(int i = 0; i < n; i++){

        int req = vp[i].ss - vp[i].ff + 2;

        int l = i != 0 ? vp[i-1].ss + 1 : 0;
        auto lo = po.lower_bound(l);

        int r = vp[i].ff;
        auto up = po.lower_bound(r);


        for(auto j = lo; j != up; j++){
            auto [x,v] = *j;
            if(x >= r) break;
            for(auto &el : v) pq.push(el);
        }


        while(pq.size()){
            if(jmp >= req) break;
            jmp += pq.top();
            pq.pop();
            ans++;
        }
        
        if(jmp < req){
            cout << -1 << nl;
            return;
        }
        
    }

    cout << ans << nl;
    
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