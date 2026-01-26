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
#define nl               endl
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());



void solve(){
    auto query = [&](int l, int r){
        cout << "? " << l << " " << r << nl;
        int res;
        cin >> res;
        return res;
    };

    int lo = 2, hi = 999;

    while(lo < hi){
        int m1 = lo + (hi - lo)/3;
        int m2 = hi - (hi - lo)/3;

        int check = query(m1,m2);

        if(check == (m1+1)*(m2+1)) hi = m1;
        else if(check == (m1) * (m2+1)) lo = m1+1, hi = m2;
        else lo = m2+1;
    }

    cout <<"! " << lo << nl;
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