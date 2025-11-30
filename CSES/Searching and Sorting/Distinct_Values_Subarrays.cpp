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
    int n; cin >> n;
    vector<int> v(n);
    inp(v);
    map<int,int> mp,ind;


    int l = 0, ans = n;

    for(int r = 0; r < n; r++){
        mp[v[r]]++;

        while(mp[v[r]] > 1){
            if(mp[v[l]] > 0) mp[v[l]]--;
            if(mp[v[l]] == 0) mp.erase(v[l]);
            l++;
        }

        ind[l] = r;
    }

    vector<pair<int,int>> vp;

    for(auto &[l,r] : ind) {
        int val = r - l + 1;
        ans += (val*(val-1))/2;
        vp.pb({l,r});
    }

    for(int i = 1; i < vp.size(); i++){
        auto [x,y] = vp[i-1];
        auto [l,r] = vp[i];
        if(y - l + 1 > 1){
            int val = y - l + 1;
            ans -= (val*(val-1))/2;
        }
    }
    
    cout << ans  << nl;
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