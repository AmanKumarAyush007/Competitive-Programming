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
    vector<int> v(n);
    inp(v);

    vector<int> pre = v;

    for(int i = 1; i < n; i++){
        pre[i] = max(pre[i-1], v[i]);
    }

    int ans = 0;

    for(int i = n-1; i >= 0; i--){
        if(i&1){
            v[i] = pre[i];
        }
    }


    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            int x = inf;
            if(i-1 >= 0) x = min(x,v[i-1]);
            if(i+1 < n) x = min(x,v[i+1]);

            x--;

            ans += max(0LL, (v[i] - x));
        }
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