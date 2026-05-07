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


// best code of knapsack
void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> weight(n);
    inp(weight);

    vector<int> val(n);
    inp(val);

    vector<int> dp(x+5,0);

    for(int i = 0; i < n; i++){
        for(int j = x; j >= weight[i]; j--){
            dp[j] = max(dp[j], val[i] + dp[j - weight[i]]);
        }
    }
    
    cout << dp[x] << nl;
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