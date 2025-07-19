#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n,k;
    cin >> n >> k;
    vector<pair<int,pair<int,int>>> v;
    while(n--){
        int l,r,x;
        cin >> l >> r >> x;
        v.pb({x,{l,r}});
    }
    sort(all(v));
    debug(v);

    for(int i = 0; i < v.size(); i++){
        if(k <= v[i].ss.ss && k >= v[i].ss.ff){
            if(k < v[i].ff) k = v[i].ff;
        }
    }
    cout << k << nl;
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