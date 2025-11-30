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
    vector<pair<int,int>> events;
    for(int i=0;i<n;i++){
        int l, r;
        cin >> l >> r;
        events.push_back({l, +1});
        events.push_back({r+1, -1});
    }

    sort(events.begin(), events.end());

    long long ans = 0;
    long long cur = 0;
    for(int i=0;i+1<(int)events.size();i++){
        cur += events[i].second;
        long long x = events[i].first;
        long long y = events[i+1].first;
        if(cur >= 2) {
            ans += (y - x);
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