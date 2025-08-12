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
    vector<int> a(n), b(n);
    inp(a)
    inp(b)

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans += abs(a[i] - b[i]);
    }

    vector<pair<int,int>> vp(n);
    
    for(int i = 0; i < n; i++){
        vp[i].ff = min(a[i],b[i]);
        vp[i].ss = max(a[i],b[i]);
    }

    sort(all(vp));

    vector<int> gaps;

    for(int i = 1; i < n; i++){
        if(vp[i-1].ss < vp[i].ff) gaps.pb(vp[i].ff - vp[i-1].ss);
        else {
            cout << ans << nl;
            return;
        }
    }

    sort(all(gaps));

    cout << ans + (2*gaps[0]) << nl;
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