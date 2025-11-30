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
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    vector<bool> dp(n+1,false);
    dp[0] = true;

    for(int i = 1; i <= n; i++){
        if(dp[i-1]) {
            if(i+v[i] <= n) dp[i+v[i]] = true;
        }
        if((i-(v[i]+1) >= 0) && dp[i-(v[i]+1)]){
            dp[i] = true;
        }
    }

    if(dp[n]) cout << "YES\n";
    else cout << "NO\n";
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