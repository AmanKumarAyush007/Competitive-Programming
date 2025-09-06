#include<bits/stdc++.h>
using namespace std;

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


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n;
    cin >> n;
    vector<int> v(n+1,0), dp(n+1,0);
    for(int i = 1; i < n+1; i++){
        cin >> v[i];
    }

    unordered_map<int,vector<int>> occ;

    for(int i = 1; i <= n; i++){
        occ[v[i]].pb(i);
    }


    for(int i = 1; i <= n; i++){
        int x = v[i];
        auto it = lower_bound(occ[x].begin(), occ[x].end(), i);
        int ind = it - occ[x].begin();

        if(ind >= x - 1){
            int ocxind = ind - (x - 1);
            int pre = occ[x][ocxind];
            pre--;
            dp[i] = x + dp[pre];
        }
        
        dp[i] = max(dp[i],dp[i-1]);
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