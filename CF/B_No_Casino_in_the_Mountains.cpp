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
    int n , k;
    cin >> n >> k;
    vector<int> v(n);
    inp(v)
    debug(v);

    int i = 0, j = 0, ans = 0;

    int rem = k;
    while(i < n){
        int d = j;
        while(j < n && v[j] == 0 && rem > 0){
            rem--;
            j++;
        }

        
        if(d != j) i = j;
        else {
            j++;
            i = j;
        }


        if(rem <= 0) {
            ans++;
            j++;
            i = j;
            debug(i,j);
        }

        rem = k;
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