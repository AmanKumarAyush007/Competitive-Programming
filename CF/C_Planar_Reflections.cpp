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

const int mod = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;
    
    int dp[n][k][2];

    for(int i = 0; i < n; i++){
        dp[i][0][0] = dp[i][0][1] = 1;
    }

    for(int j = 1; j < k; j++){
        for(int i = n-1; i >= 0; i--){
            int v1 = 1, v2 = 1;
            if(i-1 >= 0) v1 = dp[i-1][j-1][0];
            if(i+1 < n) v2 = dp[i+1][j][1];
            dp[i][j][1] = (v1 + v2) % mod;
        }

        for(int i = 0; i < n; i++){
            int v1 = 1, v2 = 1;
            if(i-1 >= 0) v1 = dp[i-1][j][0];
            if(i+1 < n) v2 = dp[i+1][j-1][1];

            dp[i][j][0] = (v1 + v2)%mod;
        }
    }


    cout << dp[0][k-1][1] << nl;
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