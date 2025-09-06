#include <bits/stdc++.h>
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

// --------------------- Mint ---------------------
struct mint {
    static const int MOD = 998244353;
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


int n;
vector<int> v(200005 + 5,0);
vector<mint> dp(200005 + 5);  

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    fill(all(dp), mint(0));
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        if(v[i] == v[i-1]) dp[i] += dp[i-1];
        if(i >= 2 && v[i] == v[i-2] + 1) dp[i] += dp[i-2];
    }

    cout << (dp[n] + dp[n-1]).v << nl; 
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
