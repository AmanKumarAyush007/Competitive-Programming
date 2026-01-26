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
    int n,q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    inp(a);
    inp(b);

    for(int i = 0; i < n; i++){
        if(b[i] > a[i]) swap(a[i],b[i]);
    }

    vector<int> pre = a;
    for(int i = n-2; i >= 0; i--){
        pre[i] = max(pre[i], pre[i+1]);
    }
    prefixsum(pre);

    while(q--){
        int l, r;
        cin >> l >> r;

        l--, r--;

        int tot = pre[r] - (l > 0 ? pre[l-1] : 0);

        // if(l > 0 && a[l-1] > a[l]) tot += a[l-1] - a[l];
        // if(r < n-1 && a[r+1] > a[r]) tot += a[r+1] - a[r];

        cout << tot << " ";
    }

    cout << nl;
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