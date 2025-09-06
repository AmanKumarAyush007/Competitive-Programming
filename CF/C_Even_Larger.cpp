#include<bits/stdc++.h>
using namespace std;

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


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);
    int ans = 0;

    for(int i = 1; i < n; i+=2){
        int diff = max(0LL,v[i-1] - v[i]);
        v[i-1] -= diff;
        ans += diff;
    }


    for(int i = 1; i < n; i+=2){
        int adj = v[i-1];
        if(i+1 < n) {
            adj += v[i+1];
            if(adj > v[i]){
                int diff = adj - v[i];
                ans += diff;
                v[i+1] = max(v[i+1] - diff, 0LL);
                int rest = max(diff - v[i+1], 0LL);
                v[i-1] -= rest;
            }
        }
        else if(adj > v[i]) ans += adj;
    }

    cout << ans;
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