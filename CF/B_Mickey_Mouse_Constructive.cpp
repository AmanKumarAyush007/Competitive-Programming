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

const int N = 200000 + 5;
int divisors[N];

void precompute() {
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            divisors[j]++;
        }
    }
}

void solve(){
    int x,y;
    cin >> x >> y;

    int ans = (x == y ? 1 : divisors[abs(x-y)]);

    cout << ans << nl;
    

    for(int i = 0; i < x; i++){
        cout << 1 << " ";
    }
    for(int i = 0; i < y; i++){
        cout << -1 << " ";
    }
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