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

void solve(){
    int n;
    cin >> n;
    int x;
    cin >> x;

    int ans = 0;

    if(n == 1){
        if(x == 0) ans = -1;
        else ans = x;
    }
    else if(setbit(x) >= n) ans = x;
    else if((n - setbit(x)) % 2 == 0) ans = x + n - setbit(x);
    else{
        if(x >= 2) ans = x + n - setbit(x) + 1;
        else ans = x + n - setbit(x) + 3;
    }

    cout << ans;
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