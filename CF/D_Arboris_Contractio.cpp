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
    map<int,int> mp;
    n--;

    while(n--){
        int x,y;
        cin >> x >> y;
        if(x > y) swap(x,y);
        mp[x]++;
        mp[y]++;

    }

    debug(mp);

    int ans = inf, cnt = 0;

    for(auto &[a,b] : mp){
        if(b == 1) cnt++;
        ans = min(ans,b);
    }

    if(cnt >= n-1) ans = 0;
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