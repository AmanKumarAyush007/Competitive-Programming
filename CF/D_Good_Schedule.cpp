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
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    inp(a);
    inp(b);

    int ans = 0;

    vector<int> len(n);
    int prev = -1;

    for(int i = 0; i < n; i++){
        if(a[i] == 1 || b[i] == 1) prev = i;
        len[i] = i - prev;
        ans += len[i];
    }


    vector<int> dp(n+5, n-1);

    for(int i = n-1; i >= 0; i--){
        if(a[i] == b[i]) {
            dp[a[i]] = dp[a[i]+1];
            if(a[i] == 1){
                int l = (i > 0 ? len[i-1] : 0);
                int r = 1 + dp[1] - i;
                ans += r + (l*r);
            }
        }
        else {
            dp[a[i]] = i-1;
            dp[b[i]] = i-1;
        }    
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