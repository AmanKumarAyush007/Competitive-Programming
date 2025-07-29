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

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

int cntG(int x){
    if(x < 1) return 0;

    // x - (those number jo {2,3,5,7} se divible na ho);

    int ans = x;

    ans -= x / 2;
    ans -= x / 3;
    ans -= x / 5;
    ans -= x / 7;

    ans += x / 10;  
    ans += x / 6;   
    ans += x / 14;  
    ans += x / 15;  
    ans += x / 21;  
    ans += x / 35;  

    ans -= x / 30;
    ans -= x / 42;
    ans -= x / 70;
    ans -= x / 105;

    ans += x / 210; 

    return ans;

}

void solve(){
    int l,r;
    cin >> l >> r;
    cout << cntG(r) - cntG(l-1);
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