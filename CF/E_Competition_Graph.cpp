#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)


const int MOD = 998244353;

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

    int ans = 0;

    for(int i = 3; i <= k; i++){
        ans += (nCr(n,i) * fact[i-1]) % MOD;
        ans %= MOD;
    }

    cout << ans;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int max_n = 100005;
    precompute(max_n); 

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}