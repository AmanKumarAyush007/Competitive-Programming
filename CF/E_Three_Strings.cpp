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
    string a,b,c;
    cin >> a >> b >> c;

    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n+5, vector<int> (m+5, 1e9));
    dp[0][0] = 0;


    for(int i = 1; i <= n; i++){
        dp[i][0] = dp[i-1][0] + (a[i-1] != c[i-1]);
    }
    for(int j = 1; j <= m; j++){
        dp[0][j] = dp[0][j-1] + (b[j-1] != c[j-1]);
    }
    

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = min(
                dp[i-1][j] + (a[i-1] != c[i+j-1]),
                dp[i][j-1] + (b[j-1] != c[i+j-1])
            );
        }
    }

    cout << dp[n][m] << nl;
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