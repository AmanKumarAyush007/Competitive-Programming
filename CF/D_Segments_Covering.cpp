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


const int MOD = 998244353;

int power(int base, int exp, int mod) {
    int res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2; 
    }
    return res; 
}
int modInverse(int n, int mod) {
    return power(n, mod - 2, mod);
}

struct range
{
    int p,q,r;
};

map<int,vector<range>> mp;

vector<int> dp(200007,-1);

int n,m;

int rec(int x){
    if(x > m) return 1;

    if(dp[x] != -1) return dp[x];

    int ans = 0;
    
    for(auto &ob : mp[x]){
        int p = ob.p;
        int q = ob.q;
        int r = ob.r;
        int val = 1;

        val *= modInverse(q-p,MOD);
        val %= MOD;
        val *= p;
        val %= MOD;

        ans += (val * rec(r+1)) % MOD;
        ans %= MOD;
    }

    return dp[x] = ans % MOD;
}


void solve() {
    cin >> n >> m;

    fill(all(dp),-1);

    int ans = 1;

    for(int i = 0; i < n; i++){
        int l,r,p,q;
        cin >> l >> r >> p >> q;
        
        ans *= (q-p);
        ans %= MOD;
        ans *= modInverse(q,MOD);
        ans %= MOD;
        
        range rat;
        rat.q = q;
        rat.r = r;
        rat.p = p;
        mp[l].pb(rat);
    }

    ans *= rec(1);
    cout << ans % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}