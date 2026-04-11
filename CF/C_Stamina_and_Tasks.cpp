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
    int n;
    cin >> n;

    vector<double> c(n);
    vector<double> f(n);

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        c[i] = x;
        f[i] = 1.0 - y/100.0;
    }

    vector<double> dp(n+1, 0.0);  // dp[i] -> if we start from i and end at n-1 i.e. [i, n-1] range, then what would be the max points can get. Therefore dp[0] is the final ans;

    for(int i = n-1; i >= 0; i--){
        dp[i] = max(dp[i+1], c[i] + f[i]*dp[i+1]);
    }

    cout << fixed << setprecision(10) << dp[0] << nl;
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