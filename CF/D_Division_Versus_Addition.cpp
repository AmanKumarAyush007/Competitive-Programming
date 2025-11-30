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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    inp(v)

    vector<int> a(n,0),b(n,0);

    for(int i = 0; i < n; i++){
        int k = lg(v[i]);
        int topo = (1LL << k);
        if(v[i] == (topo+1)) a[i]++;
        else if(v[i] != (topo)) b[i]++;
        v[i] = k;
    }


    prefixsum(v);
    prefixsum(a);
    prefixsum(b);


    while(k--){
        int l,r;
        cin >> l >> r;
        l--, r--;

        int ans = v[r] - ((l-1 >= 0) ? v[l-1] : 0);

        ans += (a[r] - ((l-1 >= 0) ? a[l-1] : 0))/2;
        ans += b[r] - ((l-1 >= 0) ? b[l-1] : 0);
        

        cout << ans;
        cout << nl;
    }
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