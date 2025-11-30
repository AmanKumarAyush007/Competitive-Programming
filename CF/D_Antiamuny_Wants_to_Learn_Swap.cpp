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


void solve(){
    int n,q;
    cin >> n >> q;

    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    vector<int> bad(n+1, 0);
    for(int i=1;i<=n-2;i++){
        if(a[i] > a[i+1] && a[i+1] > a[i+2]) bad[i] = 1;
    }

    vector<int> pref(n+1, 0);
    for(int i=1; i<=n; i++){
        pref[i] = pref[i-1] + (i <= n-2 ? bad[i] : 0);
    }

    while(q--){
        int l,r;
        cin >> l >> r;
        int len = r - l + 1;
        if(len < 3){
            cout << "YES" << nl;
            continue;
        }
        int cnt = pref[r-2] - pref[l-1];
        if(cnt > 0) cout << "NO" << nl;
        else cout << "YES" << nl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
