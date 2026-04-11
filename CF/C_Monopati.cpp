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

using pi = pair<int,int>;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    inp(a);
    inp(b);

    vector<int> premn, premx, suffmx, suffmn;
    premn = premx = a;
    suffmn = suffmx = b;

    for(int i = 1; i < n; i++){
        premn[i] = min(premn[i-1], premn[i]);
        premx[i] = max(premx[i-1], premx[i]);
    }

    for(int i = n-2; i >= 0; i--){
        suffmx[i] = max(suffmx[i+1], suffmx[i]);
        suffmn[i] = min(suffmn[i+1], suffmn[i]);
    }

    vector<pi> vp(n);
    for(int i = 0; i < n; i++){
        vp[i] = {min(premn[i],suffmn[i]), max(premx[i], suffmx[i])};
    }
    
    sort(all(vp));
    

    vector<int> l(n),r(n);
    for(int i = 0; i < n; i++){
        l[i] = vp[i].ff;
    }


    r[n-1] = vp[n-1].ss;
    for(int i = n-2; i >= 0; i--){
        r[i] = min(r[i+1],vp[i].ss);
    }

    int ans = 0;

    for(int i = 1; i <= l[n-1]; i++){
        auto it = lower_bound(all(l), i);

        int ind = it - l.begin();
        ans += 2*n - r[ind] + 1;
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