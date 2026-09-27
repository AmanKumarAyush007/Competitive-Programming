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
    vector<int> a(n), b(n);
    inp(a);
    inp(b);

    if(a == b){
        cout << 0 << nl;
        return;
    }

    int cnt = 0;
    bool o = 0;
    bool z = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1 && b[i] == 0) cnt++;
        else if(a[i] == b[i]){
            if(a[i]) o = 1;
            else z = 1;
        }
    }

    if(cnt) cout << (cnt%2 ? 1 : 2) << nl;
    else if(o && z) cout << 2 << nl;
    else cout << -1 << nl;
    
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