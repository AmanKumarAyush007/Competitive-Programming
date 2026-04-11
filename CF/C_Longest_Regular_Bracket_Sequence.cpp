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
    string s;
    cin >> s;

    int n = s.size();

    vector<int> dp(n, 0);

    for(int i = 1; i < n; i++){
        if(s[i] == ')'){
            int j = i - dp[i-1] - 1;
            if(j >= 0 && s[j] == '('){
                dp[i] = dp[i-1] + 2;     
                if(j-1 >= 0) dp[i] += dp[j-1];
            }
        }
    }


    int mx = *max_element(all(dp));
    int cnt = 0;
    for(auto &i : dp) if(i == mx) cnt++;

    if(mx == 0) cnt = 1;

    cout << mx << " " << cnt << nl;
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