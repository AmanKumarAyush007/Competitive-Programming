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
    vector<int> v(n);
    inp(v)

    int ans = sm(v);

    map<int,int>mp;

    mp[v[0]]++;
    v[0] = 0;
    int mx = 0;
    
    for(int i = 1; i < n; i++){
        mp[v[i]]++;
        if(mp[v[i]] >= 2) mx = max(v[i],mx);
        v[i] = mx;
    }

    ans += sm(v);
    debug(v);


    if(v.size() >= 2){
        mp.clear();
        mp[v[1]]++;
        v[1] = 0;
        mx = 0;
        

        for(int i = 2; i < n; i++){
            mp[v[i]]++;
            if(mp[v[i]] >= 2) mx = max(v[i],mx);
            v[i] = mx;
        }
    }

    debug(v);


    for(int i = 1; i < n; i++){
        v[i] += v[i-1];
    }

    ans += sm(v);

    // debug(v);

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