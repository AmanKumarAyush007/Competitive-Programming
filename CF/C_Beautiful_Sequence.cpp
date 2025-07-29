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
#define lg(x)      (63 - __builtin_clzll(x)) //log base 2


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
#define debug(x...)
#endif


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
const int mod = 998244353;


void precompute(int n) { 
    
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    
    inv_fact[n] = modInverse(fact[n], mod);
    for (int i = n - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
}
int nCr(int n, int r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return (fact[n] * inv_fact[r] % mod * inv_fact[n - r]) % mod;
}




void solve(){
    int n;
    cin >> n;
    vector<int> v(n),pre(n);
    inp(v)
    if(v[0] == 2) pre[0] = 1;
    for(int i = 1; i < n; i++){
        if(v[i] == 2) pre[i] = pre[i-1] + 1;
        else pre[i] = pre[i-1];
    }

    vector<int> ind1, ind3;
     
    auto it = [&](int x){
        vector<int> tk;
        for(int i = 0; i < n; i++){
            if(v[i] == x)tk.pb(i);
        }
        return tk;
    };

    ind1 = it(1);
    ind3 = it(3);

    vector<int> po;
    for(int i = 0; i < ind3.size(); i++){
        po.pb(power(2,pre[ind3[i]],mod) % mod);
    }

    for(int i = ind3.size() - 2; i >= 0; i--){
        po[i] = (po[i+1] + po[i]) % mod;
    }


    int ans = 0;

    for(int i = 0; i < ind1.size(); i++){

        int x = pre[ind1[i]] % mod;
        int y = power(2,x,mod) % mod;
        
        auto it = upper_bound(all(ind3), ind1[i]+1);
        
        if(it != ind3.end()){
            int ind = it - ind3.begin();
            ans = (ans + ((power(power(2,x,mod),mod-2,mod)%mod) * ((((po[ind]%mod) - ((power(2,x,mod)%mod)*((ind3.size() - ind)%mod)%mod) + mod) % mod)%mod))) % mod ;
            ans %= mod;
        }
        else break;

    }


    cout << ans << nl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int max_n = 200000 + 5;
    precompute(max_n); 

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}