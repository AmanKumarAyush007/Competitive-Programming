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
    
    sort(all(a));
    sort(all(b));
    
    set<int> st;
    for(auto &i : a) st.insert(i);
    for(auto &i : b) st.insert(i);

    int ans = 0;

    for(auto &i : st){
        auto it = lower_bound(all(a),i);
        int x = it - a.begin();

        it = lower_bound(all(b),i);
        int y = it - b.begin();

        if((x - y) <= k){
            ans = max(ans,(n-y)*i);
        }
        
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