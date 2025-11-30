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
#define inp(v)           for(auto &x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x))
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());

int N = 200005;
vector<vector<int>> divisors(N);

void precompute(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            divisors[j].pb(i);
        }
    }
}

void solve(){
    int n; 
    cin >> n;
    vector<int> a(n); inp(a);

    vector<int> counts(n+1,0), results;
    int currG = 0, maxG = 0;

    for(int i = 0; i < n; i++){
        int val = a[i];
        int oldG = currG;

        if(currG == 0) currG = val;
        else currG = __gcd(currG, val);

        for(auto &d : divisors[val]){
            if(d <= n) counts[d]++;
        }

        if(currG < oldG || i == 0){
            maxG = 0;
            for(int j = 2*currG; j <= n; j += currG){
                maxG = max(maxG, counts[j]);
            }
        } else {
            int max_prime = -1;
            for(auto &d : divisors[val]){
                if(d > currG && d % currG == 0 && d <= n){
                    max_prime = max(max_prime, counts[d]-1);
                }
            }
            if(max_prime == maxG) maxG++;
        }

        results.pb(maxG);
    }

    for(auto &x : results) cout << x << " ";
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t; cin >> t;
    while(t--) solve();
    return 0;
}
