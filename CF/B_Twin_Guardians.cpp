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

int N = 1e6;  
vector<bool> isprime(N + 1, true);

void precompute() {
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isprime[j] = false;
            }
        }
    }
}


void solve(){
    int a,b;
    cin >> a >> b;
    
    if(b-a == 2 && isprime[a] && isprime[b]) cout << "Y";
    else cout << "N";
    
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}