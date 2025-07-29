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

    if(n == 1){
        cout << 0 << nl;
        return;
    }

    map<int,int> mp;

    for(int i = 0; i < n; i++){
        mp[v[i]] = i;
    }

    vector<int> len(n+1,1);

    for(int i = 1; i < n; i++){
        if(mp[i] < mp[i+1]) len[i+1] = len[i] + 1;
    }

    int ans = n;

    for(int i = 1; i <= n; i++){
        int r = i;
        int l = r - len[i] + 1;
        int ri = n - r;
        int li = l - 1;
        ans = min(ans,max(ri,li));
    }

    cout<< ans << nl;
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