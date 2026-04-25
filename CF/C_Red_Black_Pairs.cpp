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

    vector<string> s(2);
    cin >> s[0] >> s[1];

    vector<int> dp(n+1, 1e9);

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        dp[i] = min(dp[i-1] + (s[0][i-1] != s[1][i-1]), dp[i]);
        if(i >= 2) dp[i] = min(dp[i-2] + (s[0][i-1] != s[0][i-2]) + (s[1][i-1] != s[1][i-2]), dp[i]);
    }

    
    cout << dp[n] << nl;
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