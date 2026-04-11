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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), c(n);
    inp(a);
    inp(c);

    map<int,int> mp;
    for(int i = 0; i < n; i++){
        mp[a[i]] = c[i];
    }


    int ans = 0;

    for(auto &[x,y] : mp){
        int cnt = y;
        int cnt1 = (mp.count(x+1) ? mp[x+1] : 0);

        int k1 = min(cnt, m/x);

        int rem = m - x*k1;

        int k2 = min(cnt1, rem/(x+1));
        
        int ex = m - (k1*x + k2*(x+1));

        int p = min({ex, k1, cnt1 - k2});

        ans = max(ans, (k1 - p)*x + (k2 + p)*(x+1));
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