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
    int n,c;
    cin >> n >> c;
    vector<int> v(n);
    inp(v);

    vector<int> pre = v;
    prefixsum(pre);

    int mx = v[0] + c;
    int ind = 0;

    for(int i = 1; i < n; i++){
        if(v[i] > mx){
            mx = v[i];
            ind = i;
        }
    }

    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        if(pre[i] + c >= mx) ans[i] = i;
        else ans[i] = i + 1;
    }

    ans[ind] = 0;

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