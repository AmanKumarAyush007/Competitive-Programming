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

set<int> dp;

void rec(int n){
    if(n < 2) return;
    int x = n/2;
    int y = n - x;

    if(!dp.count(x)) {
        dp.insert(x);
        rec(x);
    }
    if(!dp.count(y)) {
        dp.insert(y);
        rec(y);
    }
}


void solve(){
    int n,k;
    cin >> n >> k;

    dp.insert(0);
    dp.insert(1);
    dp.insert(n);

    rec(n);
    // debug(dp);

    int ans = -1;

    if(dp.count(k)){
        ans = 0;
        while(n > k){
            ans++;
            n /= 2;
        }
    }
    

    cout << ans << nl;
    dp.clear();
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