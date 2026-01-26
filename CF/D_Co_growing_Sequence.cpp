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
// 11 - 8 2 1
// 13 - 8 4 1


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    int xr = v[0];
    vector<int> ans(n,0);
    

    for(int i = 1; i < n; i++){
        int x = 0;
        for(int j = 0; j < 32; j++){
            int bt = (1LL << j);
            if((v[i-1]&bt) && ((v[i]&bt)== 0)){
                x |= bt;
            }
        }
        v
        ans[i] = x;
    }

    for(auto &i : ans) cout << i << " ";
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