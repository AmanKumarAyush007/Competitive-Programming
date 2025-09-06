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

// --------------------- Mint ---------------------
struct mint {
    static const int MOD = 1000000007;
    int v;
    mint(long long _v = 0) {
        if (_v < 0) _v = _v % MOD + MOD;
        if (_v >= MOD) _v %= MOD;
        v = int(_v);
    }
    explicit operator int() const { return v; }

    mint& operator+=(const mint& o) { if ((v += o.v) >= MOD) v -= MOD; return *this; }
    mint& operator-=(const mint& o) { if ((v -= o.v) < 0) v += MOD; return *this; }
    mint& operator*=(const mint& o) { v = int((1LL * v * o.v) % MOD); return *this; }
    mint& operator/=(const mint& o) { return *this *= o.inv(); }

    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }

    mint pow(long long p) const {
        mint a = *this, res = 1;
        while (p > 0) {
            if (p & 1) res *= a;
            a *= a;
            p >>= 1;
        }
        return res;
    }
    mint inv() const { return pow(MOD - 2); }
};
// ------------------------------------------------



void solve(){
    int l,r,k;
    cin >> l >> r >> k;
    if(k >= 10) cout << 0;
    else{
        
        int x = (9/k) + 1;

        mint ans = mint(x).pow(r) - mint(x).pow(l);

        cout << ans.v;

    }
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