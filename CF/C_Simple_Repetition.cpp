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


vector<int> sieve(int limit) {
    vector<bool> is_prime(limit + 1, true);
    vector<int> primes;
    for (int p = 2; p <= limit; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
    return primes;
}

bool ck(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    int sqrt_n = sqrt(n);
    vector<int> small_primes = sieve(sqrt_n);

    for (int p : small_primes) {
        if (n % p == 0) {
            return false;
        }
    }
    return true; 
}


void solve(){
    int n, k;
    cin >> n >> k;

    if(n == 1 && k == 2){
        cout << "YES\n";
        return;
    }
    if(k >= 2) {
        cout << "NO\n";
        return;
    }

    cout << ((ck(n)) ? "YES" : "NO");    
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