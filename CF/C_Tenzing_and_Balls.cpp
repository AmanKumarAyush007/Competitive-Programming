#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)
#define lg(x)      (63 - __builtin_clzll(x)) //log base 2


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n;
    cin >> n;
    vector<int> v(n+1),mx(n+5,-1e9), dp(n+1);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        dp[i] = max(dp[i-1], i + mx[v[i]]);
        mx[v[i]] = max(mx[v[i]], dp[i-1] - (i-1));
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