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
    vector<int> v(n);
    inp(v);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int l = 0, r = 0;
        for(int j = 0; j < i; j++) if(v[j] > v[i]) l++;
        for(int j = i+1; j < n; j++) if(v[j] > v[i]) r++;
        ans += min(l,r);
    }
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