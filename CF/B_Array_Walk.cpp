#include<bits/stdc++.h>
using namespace std;

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


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n,k,z;
    cin >> n >> k >> z;
    vector<int> v(n), pref(n);
    inp(v)

    pref = v;

    prefixsum(pref);

    
    int bestPair = 0;
    int ans = 0;

    for (int i = 0; i <= k; i++){  
        if (i < n - 1) bestPair = max(bestPair, v[i] + v[i + 1]);
        int rem = k - i;         
        int lefts = min(z, rem / 2);
        ans = max(ans, pref[i] + 1LL * bestPair * lefts);
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