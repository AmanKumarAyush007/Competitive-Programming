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

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    map<int,int> mp;

    for(auto &i : v) mp[i]++;

    vector<pair<int,int>> vp;

    for(auto &[a,b] : mp) vp.pb({b,a});

    sort(all(vp),greater<pair<int,int>>());


    int ans = 1;

    for(int i = 0; i < vp.size(); i++){
        auto [a,b] = vp[i];

        ans *= (a+1);

        ans %= mod;
    }

    cout << ans-1 << nl;
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