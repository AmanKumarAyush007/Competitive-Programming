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
    if(n == 1){
        cout << 1;
    }
    else{
        int l = n*n;
        int ans = max((l + l-1 + max(0LL,l-n)), (l-1 + ((n >= 2) ? (l-1-n) : 0) + ((n > 2) ? l-2 : 0) ) + l);
        ans = max(ans,max(0LL,l-n) + ((n >= 2) ? (l-1-n) : 0) + ((2 < n) ? (l-n-n) : 0)+ l);
        ans = max(ans,((n >= 2) ? (l-1-n) : 0) + (n > 2 ? l-n-1-n : 0) + (n > 2 ? l-n-2 : 0) + max(0LL,l-n) + l-1);
        cout << ans;
    }
    cout << nl;
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