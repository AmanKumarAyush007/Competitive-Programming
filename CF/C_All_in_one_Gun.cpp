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
    int n, h, k;
    cin >> n >> h >> k;
    vector<int> v(n);
    inp(v);

    int ans = 0;

    int tot = sm(v);


    if(tot <= h){
        ans += n*(h/tot) + (h/tot - (h % tot == 0))*k;
        h -= tot * (h/tot);
    }


    if(h <= 0){
        cout << ans << nl;
        return;
    }

    vector<int> pre = v;
    prefixsum(pre);

    vector<int> premn = v, suffmx = v;
    for(int i = 1; i < n; i++){
        premn[i] = min(premn[i-1],premn[i]);
    }
    for(int i = n-2; i >= 0; i--){
        suffmx[i] = max(suffmx[i+1],suffmx[i]);
    }
    

    for(int i = 0; i < n; i++){
        if(pre[i] >= h || (pre[i] + (suffmx[i+1] - premn[i])) >= h) {
            ans += i+1;
            break;
        }
    }

    cout << ans  << nl;
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