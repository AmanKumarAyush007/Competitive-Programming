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
    int n, K;
    cin >> n >> K;
    vector<int> P(n+1), dp(n+1);
    for(int i=1;i<=n;i++) cin >> P[i];

    deque<pair<int,int>> low, high; 
    // low  -> increasing prices
    // high -> decreasing prices

    
    dp[0] = 0;

    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1];

        // remove invalid from low
        while(!low.empty() && low.front().first > P[i] - (K+1))
            low.pop_front();

        if(!low.empty())
            dp[i] = max(dp[i], low.front().second + 1);

        // remove invalid from high
        while(!high.empty() && high.front().first < P[i] + (K+1))
            high.pop_front();

        if(!high.empty())
            dp[i] = max(dp[i], high.front().second + 1);

        int val = dp[i-1];

        // insert into low (keep increasing)
        while(!low.empty() && low.back().second <= val)
            low.pop_back();
        low.emplace_back(P[i], val);

        // insert into high (keep decreasing)
        while(!high.empty() && high.back().second <= val)
            high.pop_back();
        high.emplace_back(P[i], val);
    }

    cout << dp[n] << "\n";
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