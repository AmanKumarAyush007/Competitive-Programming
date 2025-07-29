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

map<int,int> dp;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    int ans = -1,curr = -1;
    
    for(int i = 0; i < n; i++){
        dp[v[i]] = max(dp[v[i]],dp[v[i] - 1] + 1);

        if(ans < dp[v[i]]){
            curr = v[i];
            ans = dp[v[i]];
        }
    }

    cout << ans << nl;

    vector<int> sol;
    for(int i = n-1; i >= 0; i--){
        if(v[i] == curr) {
            sol.pb(i+1);
            curr--;
        }
    }

    reverse(all(sol));
    for(auto &i : sol) cout << i << " ";
    
    cout << nl;
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