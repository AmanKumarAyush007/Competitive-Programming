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

    int tot  = 0;
    vector<int> a(n + 1), b(n + 1), dp(n + 2, n + 1); 

    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];

    for(int i = n; i >= 1; i--){
        if(a[i] == b[i]) dp[a[i]] = dp[a[i] + 1];
        else if(a[i] != b[i]) dp[a[i]] = dp[b[i]] = i;
        tot += dp[1] - i;
        debug(dp);
        debug(dp[1]-i);
    }

    cout << tot << "\n";
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