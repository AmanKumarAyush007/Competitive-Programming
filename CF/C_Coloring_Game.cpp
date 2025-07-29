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

    int x = v[n-1];

    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){

            int sum = v[i] + v[j];
            int st = j+1;
            auto itr = lower_bound(v.begin() + (j + 1), v.end(),sum);
            
            if(itr - v.begin() == st) continue;
            auto tt = itr;
            itr = prev(itr);

            auto it = upper_bound(v.begin() + st, tt,x-sum);
            if(it > itr) continue;

            ans += itr - it + 1;
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