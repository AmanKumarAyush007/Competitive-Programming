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

int n;
int a[505];
int dp[505][505];

int rec(int i, int j){
    if(i == j) return 1;
    if(j < i) return 0;
    if(j == i+1 && a[i] == a[j]) return 1;
    
    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = inf;

    if(a[i] == a[j]) dp[i][j] = rec(i+1, j-1);

    for(int k = i; k < j; k++){
        dp[i][j] = min(dp[i][j], rec(i, k) + rec(k+1, j));
    }

    return dp[i][j];
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));
    
    cout << rec(0, n-1) << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}