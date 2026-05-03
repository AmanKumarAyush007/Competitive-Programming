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
    int n,m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    inp(a);
    inp(b);

    int hi = 1e10, lo = 0;
    int ans = -1;

    auto check = [&](int x){
        for(auto &i : a){
            int l = i - x;
            int r = i + x;

            auto itl = lower_bound(all(b), l);
            
            if(itl == b.end()) return 0;
            
            auto itr = lower_bound(all(b), r);
            
            if(itr != b.end() && *itr > r) itr--;

            int lind = itl - b.begin();
            int rind = itr - b.begin();

            if(lind > rind) return 0;
        }

        return 1;
    };

    while(hi >= lo){
        int mid = (lo+hi)/2;

        if(check(mid)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    
    cout << ans << nl;
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