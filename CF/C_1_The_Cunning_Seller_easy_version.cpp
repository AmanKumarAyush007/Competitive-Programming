#include<bits/stdc++.h>
using namespace std;

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


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif


vector<int> v;
vector<int> cost(100);

void init(){
    v.pb(1);
    while(v.back() < 1e10){
        v.pb(v.back() * 3);
    }
}

void cst(){
    for(int x = 0; x < v.size(); x++){
        cost[x] = pow(3,x+1) + (x*pow(3,x-1));
    }
}

void solve(){
    int n;
    cin >> n;

    debug(n);

    int ans = 0;
    

    for(int i = v.size()-1; i >= 0; i--){
        int tk = n/v[i];
        n -= tk*v[i];
        ans += tk * cost[i];
    }
   
    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    cst();

    // debug(v);
    // debug(cost);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}