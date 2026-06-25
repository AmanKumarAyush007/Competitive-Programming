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



void solve(){
    int n, k;
    cin >> n >> k;

    string up, down;
    cin >> up >> down;

    int x = (1LL << k) + 1;


    auto fn = [&](string &s){
        return (count(all(s),'1') * count(all(s),'0'));
    };

    string mid;

    for(int i = 0; i < n; i++){
        int a = up[i] - '0';
        int b = down[i] - '0';
        int c = a^b;
        mid += '0' + c;
    }

    int can = x/3;

    int a = fn(up), b = fn(down), c = fn(mid);

    int ans = can*(a + b + c);

    if(x%3 == 2) ans += a + b;
    else if(x%3) ans += a;

    cout << ans << nl;
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