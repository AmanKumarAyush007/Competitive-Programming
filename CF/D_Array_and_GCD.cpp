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
#define allr(a)     (a).rbegin(),(a).rend()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)

vector<int> primes;

void sieveOfEratosthenes(int N) {

    vector<bool> isPrime(N + 1, true);

    if (N >= 0) isPrime[0] = false;
    if (N >= 1) isPrime[1] = false;

    for (int p = 2; p * p <= N; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= N; i += p)
                isPrime[i] = false;
        }
    }

    for (int p = 2; p <= N; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }
}


void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    inp(v)

    sort(allr(v));


    int sum = 0;
    int ans = n;
    
    for(int i = 0; i < n; i++){
        sum += v[i];
        if(sum < primes[i]){
            break;
        }
        else ans--;
    }
    
    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieveOfEratosthenes(10000000);

    for(int i = 1; i < primes.size(); i++){
        primes[i] += primes[i-1];
    }

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}