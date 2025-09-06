#include<bits/stdc++.h>
using namespace std;

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


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n;
    cin >> n;

    // a^b = n; ---------------> `eq1`  [GIVEN]
    // a^b = (a+b)/2; => 2*(a^b) = (a+b)  ---------------> `eq2`  [GIVEN]
    // => we can say a+b = 2*(common bits) + bits which comes in either a or b
    // => a+b = 2*(a&b) + (a^b)
    // Put the value of a+b in eq2
    // 2*(a^b) = 2*(a&b) + (a^b);
    // (a^b) = 2*(a&b) => n = 2*(a&b);
    // (a & b) = n/2; ---------------> `eq3`
    // Since a and b both are integers then (a&b) is also integer then n/2 must be integer 
    // Therefore, n must be divisble by 2

    //Let say a = (a&b) + (a^b) , here it is considered that all the bits which comes in either a or b is considered in a only i.e (a^b);
    // Then b = (a&b), all the common bits in a and b 

    // Using eq1 && eq3
    // then a = (n/2) + n  and b = n/2;

    // Finally we verify if a ^ b == n or not

    if(n % 2) cout << -1;
    else{
        int a = (3*n)/2;
        int b = n/2;
        if((a^b) != n) cout << -1;
        else cout << a << " " << b;
    }
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