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
    int n, sx, sy, ex,ey;
    cin >> n >> sx >> sy >> ex >> ey;

    vector<int> x(n), y(n);
    inp(x);
    inp(y);

    auto dist = [&](pair<int,int> & a, pair<int,int> &b){
        return abs(a.ff-b.ff) + abs(a.ss-b.ss);
    };

    map<int,int> top, bot;
    top[sx] = bot[sx] = sy;
    top[ex] = bot[ex] = ey;

    for(int i = 0; i < n; i++){
        if(!top.count(x[i])){
            top[x[i]] = bot[x[i]] = y[i];
            continue;
        }

        top[x[i]] = max(top[x[i]], y[i]);
        bot[x[i]] = min(bot[x[i]], y[i]);
    }

    
    vector<pair<int,int>> vtop, vbot;
    
    for(auto &[a,b] : top) vtop.pb({a,b});
    for(auto &[a,b] : bot) vbot.pb({a,b});
    
    int m = vtop.size();

    vector<vector<int>> dp(m, vector<int>(2,inf/10));

    dp[0][1] = dp[0][0] = 0;

    for(int i = 1; i < m; i++){
        int tptp = dp[i-1][1] + dist(vtop[i-1], vtop[i]);
        int tpbt = dp[i-1][1] + dist(vtop[i-1], vbot[i]);
        int bttp = dp[i-1][0] + dist(vbot[i-1], vtop[i]);
        int btbt = dp[i-1][0] + dist(vbot[i-1], vbot[i]);

        dp[i][0] = min(tptp, bttp) + dist(vtop[i], vbot[i]);
        dp[i][1] = min(tpbt, btbt) + dist(vtop[i], vbot[i]);
    }

    cout << dp[m-1][1] << nl;
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