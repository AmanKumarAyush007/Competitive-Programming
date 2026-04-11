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

const int mod = 998244353;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    int ans = 0;

    for(int i = 0; i <= 32; i++){
        int w = (1LL << i);

        int toton = 0;
        int totoff = 0;
        int cnton = 0;
        int cntoff = 0;

        int val = 0;

        for(int j = 0; j < n; j++){
            int bit = (w & v[j]);

            if(bit == 0){
                cntoff++;
            }
            else{
                swap(totoff, toton);
                swap(cntoff, cnton);
                cnton++;
            }

            totoff += cntoff;
            toton += cnton;

            val += toton % mod;
            val %= mod;
        }

        ans += (val*w) % mod;
        ans %= mod;
    }

    cout << ans << nl;
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