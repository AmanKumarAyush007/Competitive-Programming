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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    inp(a);
    inp(b);
    inp(c);

    vector<bool> ok(n,true);
    int p = n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ok[j] && a[i] >= b[(i+j)%n]){
                ok[j] = 0;
                p--;
            }
        }
    }

    ok.assign(n,true);

    int q = n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ok[j] && b[i] >= c[(i+j)%n]){
                ok[j] = 0;
                q--;
            }
        }
    }

    cout << n * p * q << nl;
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