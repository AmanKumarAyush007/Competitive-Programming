#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
// #define nl         '\n'
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
    int lo = 1, hi = 1e6;
    int ans = 0;

    while(lo <= hi){
        int mid = (lo + hi) / 2;
        cout << mid << endl;

        string res;
        cin >> res;


        if(res == ">="){
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    cout << "! " << ans << endl;
    
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