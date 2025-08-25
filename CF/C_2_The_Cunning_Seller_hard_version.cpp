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
    int n, k; 
    cin >> n >> k;

    auto smd = [&](int x)->int {
        int s = 0;
        while (x > 0) {
            s += x % 3;
            x /= 3;
        }
        return s;
    };

    int s0 = smd(n);

    if (s0 > k) { 
        cout << -1 << nl;
        return;
    }

    int kprime = ( (k & 1) == (n & 1) ) ? k : (k - 1);
    int s = min(n, kprime);

    int m = (n - s) / 2; 

    int extra = 0;
    int pow3 = 1; 

    for (int x = 0; m > 0 && pow3 <= n; ++x) {
        if (n / (pow3 * 3) == 0) break;

        int avail = n / (pow3 * 3);
        int take = min(avail, m);
        extra += take * pow3;  
        m -= take;

        if (pow3 > (inf / 3)) break; 
        pow3 *= 3;
    }


    cout << (3LL * n + extra) << nl;
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