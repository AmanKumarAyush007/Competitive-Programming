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
    int n,m;
    cin >> n >> m;

    multiset<int> ms;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ms.insert(x);
    }

    while(m--){
        int x;
        cin >> x;
        auto it = ms.lower_bound(x);

        if((it == ms.end() && ms.size()) || (ms.size() >= 2 && *it > x)) it--;

        int ans = -1;

        if(it != ms.end() && *it <= x){
            ans = *it;
            ms.erase(it);
        }

        cout << ans << nl;
    }
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