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

    vector<int> l(n), r(n), u(n), v(n);
    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i] >> u[i] >> v[i];
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        vector<int> temp;
        for(int j = 0; j < n; j++){
            if(temp.size() == i) {
                break;
            }
            if(((temp.size() + 1 < l[j]) || (temp.size() + 1 > r[j])) && ((i - temp.size() < u[j]) || (i - temp.size() > v[j]))) temp.pb(j);
        }
        if(temp.size() == i) ans = max(ans, i);
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