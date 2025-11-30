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

int dp[3005][100];

int ncr(int n, int r){
    if(n < r) return 0;
    if(n == r) return 1;
    if(r == 0) return 1;

    if(dp[n][r] != -1) return dp[n][r];

    return dp[n][r] = (ncr(n-1,r-1) + ncr(n-1,r)) % ((int)1e9+7);
}

void solve(){
    int n , m;
    cin >> n >> m;

    m *= 2;

    cout << ncr(m+n-1,m);
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    memset(dp,-1,sizeof(dp));

    while(t--){
        solve();
    }
    return 0;
}