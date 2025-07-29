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
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> v(m);
    inp(v)

    int mxfre = (n/k) + ((n%k) != 0);
    int mxL = (((n%k) == 0) ? k : n%k);
    int cnt = 0;


    debug(mxfre,mxL);

    for(int i = 0; i < m; i++){
        if(v[i] > mxfre) {
            mxL = -1;
            break;;
        }
        else if(v[i] == mxfre) mxL--;
    }
    cout << ((mxL >= 0) ? "YES" : "NO") << nl;
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