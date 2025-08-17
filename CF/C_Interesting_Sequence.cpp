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


void solve(){
    int n , k;
    cin >> n >> k;

    auto check = [&](int x){
        int left = n;
        int right = x;
        for(int i = 0 ; i < 64; i++){
            if(right == left) return (right << i);
            right >>= 1;
            left >>= 1;
        }
        return 0LL;
    };

    int ans = -1;
    int lo = n , hi = 5*(1e18);

    while(lo <= hi){
        int mid = hi - ((hi - lo) / 2);
        int curr = check(mid);
        if(curr <= k) {
            if(curr == k) ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
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