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


const int MOD = 1e9 + 7;

vector<int> fact;
vector<int> inv_fact;

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
void precompute(int n) { 
    fact.resize(n + 1);
    inv_fact.resize(n + 1);

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    inv_fact[n] = modInverse(fact[n], MOD);
    for (int i = n - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}
int nCr(int n, int r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return (fact[n] * inv_fact[r] % MOD * inv_fact[n - r]) % MOD;
}



void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    inp(v);

    sort(all(v), greater<int>());

    map<int,int> mp;

    for(auto &i : v) mp[i]++;

    int ans = 1;

    for(int i = 0; i < k; i++){
        int tot = mp[v[i]];
        int cnt = 1;
        while(i+1 < k && v[i] == v[i+1]){
            cnt++;
            i++;
        }

        ans *= nCr(tot,cnt);
        ans %= MOD;
    }

    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int max_n = 100000;
    precompute(max_n); 

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}