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
    vector<pair<pair<int,int>,int>> vp;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        vp.pb({{x,y},i+1});
    }

    sort(all(vp));

    set<int> st;

    vector<int> ans;

    for(int i = 0; i < n; i++){
        auto [a,b] = vp[i].ff;
        if(st.find(a) != st.end() && st.find(b) != st.end()) continue;
        st.insert(a);
        st.insert(b);
        ans.pb(vp[i].ss);
    }

    sort(all(ans));

    cout << ans.size() << nl;
    for(auto &i : ans) cout << i << " ";

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