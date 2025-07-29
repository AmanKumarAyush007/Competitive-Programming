#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)
#define lg(x)      (63 - __builtin_clzll(x)) //log base 2


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

vector<int> dp;
vector<int> v;

int rec(int i){
    if (i == 0) return 1;
    if (i == 1) {
        return (v[1] < v[0]) ? 3 : 2;
    }
    if (dp[i] != -1) return dp[i];
    
    if (v[i] < v[i-1]) {
        dp[i] = rec(i - 1) + i + 1;
    } else {
        dp[i] = rec(i - 2) + i + 1;
    }
    return dp[i];
}


void solve(){
    int n;
    cin >> n;
    v.resize(n);
    inp(v)

    dp.assign(n+5, -1);
    dp[0] = 1;

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans += rec(i);
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