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
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    vector<pair<int,int>> sol;
    multiset<pair<int,int>> vp;

    for(int i = 0; i < n; i++){
        if(v[i]){
            vp.insert({v[i],i});
        }
    }


    // debug(vp);

    while(vp.size() > 1){
        auto it = prev(vp.end());
        auto lft = prev(it);

        auto [fre,x] = *it;
        auto [cnt,y] = *lft;

        int sz = min(fre,cnt);

        vp.erase(it);
        vp.erase(lft);

        fre--;
        cnt--;

        if(cnt) vp.insert({cnt, y});
        if(fre) vp.insert({fre,x});


        sol.pb({x,y});
    }

    cout << sol.size() << nl;
    for(auto &[x,y] : sol) cout << x+1 << " " << y+1 << nl;
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