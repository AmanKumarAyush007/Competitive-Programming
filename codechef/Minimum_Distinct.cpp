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
#define inf              (int)1e18
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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    inp(v);

    map<int,int> mp;
    for(int i = 1; i < n; i++){
        if(v[i] != v[0]){
            mp[v[i]]++;
        }
    }

    // debug(mp);

    int x = mp.size();

    vector<pair<int,int>> vp;
    for(auto &[a,b] : mp) vp.pb({b,a});

    sort(all(vp));

    for(auto &[a,b] : vp){
        if(b <= k){
            k -= b;
            x--;
        }
        else
    }

    // debug(x);

    x++;

    cout << x << nl;
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