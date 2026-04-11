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



void solve(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    inp(v);

    int tot = sm(v);
    

    int loop = tot/n;

    int extra = v[0];


    int x = 0, y = 0, p = 0, q = 0;

    vector<int> a(v.begin() + 1 , v.end());

    sort(all(a));

    for(int i = 0; i < n; i++){
        if(a[i] == loop) y++,q++;
        else if(a[i] == loop+1) x++,p++;
        else if(a[i] < loop){
            if(extra >= loop - a[i]) {
                extra -= loop - a[i];
                a[i] = loop;
                q++;
            }
            else {
                cout << 0 << nl;
                return;
            }
        }
        else{
            cout << 0 << nl;
            return;
        }
    }

    sort(rall(a));

    for(int i = 0; i < n; i++){
        if(a[i] < loop+1 && extra > 0){
            a[i]++;
            extra--;
            p++;
        }
    }


    int ans = 0;

    int i = nCr(p,x) % MOD;
    int j = nCr(q,y) % MOD;
    int k = fact[n - (x+y)] % MOD;
    int l = fact[x] % MOD;
    int m = fact[y] % MOD;

    ans = (((((((i*j) % MOD) * k) % MOD) * l) % MOD) * m) % MOD;

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