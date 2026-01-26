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

const int mod = 998244353;
vector<vector<int>> divs(3005);

void precompute(){
    for(int i = 1; i <= 3000; i++){
        for(int j = i; j <= 3000; j += i){
            divs[j].pb(i);
        }
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    inp(v);

    if(v[0] > 1){
        cout << 0 << nl;
        return;
    }

    v[0] = 1;

    int dp[n+5][m+5];
    memset(dp,0,sizeof(dp));

    dp[0][1] = 1;

    for(int i = 0; i < n-1; i++){
        for(int j = 1; j <= m; j++){
            for(auto &x : divs[j]){
                if(x+j <= m && (!v[i+1] || v[i+1] == x+j)){
                    dp[i+1][x+j] = (dp[i+1][x+j] + dp[i][j]) % mod;
                }
            }
        }
    }


    int ans = 0;

    for(int i = 1; i <= m; i++){
        ans = (ans + dp[n-1][i]) % mod;
    }

    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}