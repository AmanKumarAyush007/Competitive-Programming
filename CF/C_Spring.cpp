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
    int n, a, b, c;
    cin >> a >> b >> c >> n;

    int A = n/a, B = n/b, C = n/c;
    int AB = n/lcm(a,b), BC = n/lcm(b,c), AC = n/lcm(a,c);
    int ABC = n/lcm(a, lcm(b,c));
    
    AB -= ABC;
    BC -= ABC;
    AC -= ABC;
    
    A -= AB + AC + ABC;
    B -= BC + AB + ABC;
    C -= AC + BC + ABC;

    auto f = [&](int x, int y, int z){
        return (x*6 + y*3 + z*2);
    };

    int ansA = f(A, AB+AC, ABC);
    int ansB = f(B, BC + AB, ABC);
    int ansC = f(C, AC+BC, ABC);

    cout << ansA << " " << ansB << " " << ansC << nl;
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