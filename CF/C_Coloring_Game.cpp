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

    int ans = 0;

    for(int i = 1; i < n-1; i++){
        for(int j = 0; j < i; j++){
            int sum = v[i] + v[j];
            int ind = n;
            auto it = lower_bound(all(v),sum);
            if(it != v.end()) ind = it - v.begin();
            int d = i;
            while(d < ind && sum + v[d] <= v[])
            ans += ind - (d+1);
            debug(sum,ind);
            debug(i,j,ans);
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