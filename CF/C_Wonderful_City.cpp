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

int sol(vector<vector<int>>&v, vector<int> &cst){
    int n = cst.size();

    vector<bool> a(n, false), b(n, false), c(n, false);
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i-1][j] + 1 == v[i][j]) c[i] = 1;
            if(v[i-1][j] == v[i][j] + 1) b[i] = 1;
            if(v[i-1][j] == v[i][j]) a[i] = 1;
        }
    }
    
    int dp[n][2];
    dp[0][0] = 0, dp[0][1] = cst[0];

    for(int i = 1; i < n; i++){
        if(a[i] && b[i] && c[i]) return inf;
    }

    for(int i = 1; i < n; i++){
        if(a[i] && b[i]){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = inf;
        }
        else if(a[i] && c[i]){
            dp[i][0] = inf;
            dp[i][1] = dp[i-1][0] + cst[i];
        }
        else if(b[i] && c[i]){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1] + cst[i];
        }
        else if(a[i]){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][0] + cst[i];
        }
        else if(b[i]){
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][1] + cst[i];
        }
        else if(c[i]){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + cst[i];
        }
        else{
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + cst[i];
        }
    }

    return min(dp[n-1][0], dp[n-1][1]);
}

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));
    for(auto &i : v) inp(i);

    vector<int> a(n), b(n);
    inp(a);
    inp(b);

    
    int ans = sol(v, a);

    if(ans >= inf) {
        cout << -1 << nl;
        return;
    }

    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            swap( v[i][j],  v[j][i]);
        }
    }

    ans += sol(v, b);

    if(ans >= inf){
        cout << -1 << nl;
        return;
    }

    cout << ans << nl;
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