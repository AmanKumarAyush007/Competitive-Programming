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
    int s;
    cin >> s;
    vector<int> v(n);
    inp(v)

    int tot = sm(v);

    if(s < tot){
        for(auto &i : v) cout << i << " ";
        cout << nl;
    }
    else {
        int diff = s - tot;
        int cnt = count(all(v),1);
        if(diff != 1) cout << -1;
        else{
            vector<int> ans;
            int x = count(all(v),0);
            while(x--) ans.pb(0);
            
            x = count(all(v),2);
            while(x--) ans.pb(2);

            x = count(all(v),1);
            while(x--) ans.pb(1);

            for(auto &i : ans) cout << i << " ";

        }
        cout << nl;
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