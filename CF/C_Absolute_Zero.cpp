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

    unordered_map<int,int> mp;

    // for(auto &i : v) mp[i]++;

    int mx = *max_element(all(v));

    if(mx == 0){
        cout << 0 << nl << nl;
        return;
    }

    int curr = 1LL << (lg(mx));

    vector<int> ans;

    auto check = [&](){
        if(mp.size() == 0) return false;
        auto [x,y] = *mp.begin();
        return (mp.size() == 1 && x == 0);
    };

    while(curr > 0){
        if(check()) break;
        mp.clear();
        for(auto &i : v) {
            mp[abs(i-curr)]++;
            i = abs(i-curr);
        }

        ans.pb(curr);
        curr >>= 1;
    }


    if(mp.size() == 1) {
        cout << ans.size() + (mp.begin()->ff != 0) << nl;
        for(auto &i : ans) cout << i << " ";
        if(mp.begin()->ff != 0) cout << (mp.begin()->ff) << " ";
        cout << nl;
    }
    else cout << -1 << nl;

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