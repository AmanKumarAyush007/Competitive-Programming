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


int dp[5005][5005];

void solve(){
    string s;
    cin >> s;
    int q;
    cin >> q;

    int n = s.size();

    vector<vector<bool>> isPal(n+5, vector<bool>(n+5, false));


    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
        isPal[i][i] = 1;
        isPal[i+1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int st = 0; st + i - 1 < n ; st++){
            int en = st + i - 1;
            isPal[st][en] = isPal[st+1][en-1] & (s[st] == s[en]);
            dp[st][en] = dp[st][en - 1] + dp[st+1][en] - dp[st+1][en - 1] + isPal[st][en];
        }
    }
    

    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << dp[l][r] << nl;
    }
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