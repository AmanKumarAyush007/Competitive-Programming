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



void solve(){
    int n;
    cin >> n;
    if(n <= 2) cout << n << nl;
    else{
        if(n&1) cout << lcm(n,lcm(n-1,n-2)) << nl;
        else{
            int ans = 0;
            for(int i = 0; i <= min(50LL,n); i++){
                for(int j = 0; j <= min(50LL,n); j++){
                    for(int k = 0; k <= min(50LL,n); k++){
                        ans = max(ans,lcm(n-i, lcm(n-j,n-k)));
                    }
                }
            }
            cout << ans << nl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}