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

const int MX = 1000;
vector<int> mnops(MX + 1, inf);

void precompute(){
    mnops[1] = 0;

    for (int i = 1; i <= MX; i++) {
        if (mnops[i] == inf) continue;

        for (int x = 1; x <= i; x++) {
            int nxt = i + i / x;
            if (nxt <= MX) {
                mnops[nxt] = min(mnops[nxt], mnops[i] + 1);
            }
        }
    }
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> b(n), c(n);
    inp(b);
    inp(c);

    vector<pair<int,int>> vp;
    int tot = 0;

    for(int i = 0; i < n; i++){
        int cost = mnops[b[i]];
        vp.pb({cost, c[i]});
        tot += cost;
    }

    int cap = min(k, tot);
    vector<int> dp(cap + 1, 0);

    for(auto &[w,val] : vp){
        for(int j = cap; j >= w; j--){
            dp[j] = max(dp[j], dp[j - w] + val);
        }
    }

    cout << *max_element(all(dp)) << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
