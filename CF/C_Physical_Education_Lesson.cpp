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

vector<int> div(int d){
    vector<int> v;

    for(int i = 1; i*i <= d; i++){
        if(d%i == 0){
            if(i%2 == 0) v.pb(i/2);

            if(i != d/i && (d/i)%2 == 0) v.pb(d/(i*2));
        }
    }

    return v;
}

void solve(){
    int n, x;
    cin >> n >> x;

    int p = n-x;
    int q = n + x - 2;
    int ans = 0;

    auto v = div(p);
    for(auto &i : v) if(i+1 >= x) ans++;

    if(x != 1){
        v = div(q);
        for(auto &i : v) if(i+1 > x) ans++;
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