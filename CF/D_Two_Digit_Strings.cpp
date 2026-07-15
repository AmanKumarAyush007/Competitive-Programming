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
    string a, b;
    cin >> a >> b;

    vector<int> pi, pj;
    for(auto &i : a) pi.pb(i-'0');
    for(auto &i : b) pj.pb(i-'0');

    
    prefixsum(pi);
    prefixsum(pj);

    
    for(auto &i : pi) i = i%10;
    for(auto &i : pj) i = i%10;

    if(pi.back() != pj.back()){
        cout << -1 << nl;
        return;
    }

    
    int n = a.size(), m = b.size();
    int dp[n+1][m+1];

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(pi[i-1] == pj[j-1]) dp[i][j] = max(dp[i][j], 1+dp[i-1][j-1]);
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