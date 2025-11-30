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
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> v(n);
    inp(v)

    struct range
    {
        int l,r,d;
    };

    vector<range> a(m);

    for(int i = 0; i < m; i++){
        cin >> a[i].l >> a[i].r >> a[i].d;
    }

    vector<int> times(n+1);

    while(k--){
        int l,r;
        cin >> l >> r;
        l--,r--;
        times[l]++;
        times[r+1]--;
    }

    prefixsum(times);
    
    vector<int> net(n,0);

    for(int i = 0; i < m; i++){
        auto &[l,r,d] = a[i];
        l--,r--;
        net[l] += times[i]*d;
        if(r+1 < n) net[r+1] -= times[i]*d;

    }

    prefixsum(net);

    for(int i = 0; i < n; i++){
        v[i] += net[i];
    }

    for(auto &i : v) cout << i << " ";
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}