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


vector<int> primes;

void precompute(int n) {

    vector<bool> isPrime(n + 1, true);

    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    for (int p = 2; p <= n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

}


void solve(){
    int n;
    cin >> n;

    auto check = [&](int i, int x){
        return (primes[i]*x) <= n;
    };

    int ans = 0;

    for(int i = 1; i < n; i++){
        int hi = primes.size() - 1;
        int lo = 0;
        int curr = 0;

        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(check(mid,i)) {
                curr = mid + 1;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        ans += curr;
    }


    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute(1e7);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}