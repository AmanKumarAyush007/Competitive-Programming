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
    int n,k;
    cin >> n >> k;
    if(n == 4 && k == 3) cout << -1 << nl;
    else if(k == n-1){
        cout << 0 << " " << n-1 << nl;
        cout << 1 << " " << n/2 - 1 << nl;


        int po = 1;

        for(int i = 2; i <= n/2; i++){
            if(i == ((n/2)- 1)) continue;
            if(i == (1LL<<po)) {
                cout << i  << " " << n - 1 - (i/2) << nl;
                po++;
            }
            else cout << i << " " << n - 1 - i << nl;
        }
    }
    else {
        for(int i = 1; i < n/2; i++){
            if(i == k || (n-1-i == k)) continue;
            cout << i << " " << n - 1 - i << nl;
        }
        cout << 0 << " " << n - 1 - k << nl;
        if(k != 0) cout << k << " " << n-1 << nl;
    }
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