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
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    inp(v);

    while(q--){
        int t, l, r;
        cin >> t >> l >> r;

        if(t == 1) v[l-1] = r;
        else{
            l--;
            r--;

            int len = r-l+1;
            int ans;
            int mid = len/2;

            if(len == 1) ans = v[l];
            else if(len&1){
                ans = min(v[l+mid], max(v[l+mid-1], v[l+mid+1]));
            }
            else ans = max(v[l + mid], v[l + mid - 1]);

            cout << ans << nl;
        }
    }
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