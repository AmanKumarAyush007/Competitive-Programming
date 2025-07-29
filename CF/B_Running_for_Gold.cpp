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

void solve(){
    int n;
    cin >> n;
    int a[n][5];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            cin >> a[i][j];
        }
    }
    map<int,int> mp;
    for(int j = 0; j < 5; j++){
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++){
            v.pb({a[i][j],i+1});
        }
        sort(all(v));
        for(int i = 0; i < 3; i++){
            mp[v[i].ss]++;
        }
        // debug(v);
    }
    
    for(auto &[a,b] : mp){
        if(b >= 3) {
            cout << a << nl;
            return;
        }
    }


    cout << -1 << nl;
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