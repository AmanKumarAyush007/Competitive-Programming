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


void solve(){
    int n,l,r,k;
    cin >> n >> l >> r >> k;
    if(n&1) cout << l << nl;
    else{
        int np = 1LL << ((63 - __builtin_clzll(l)) + 1);
        if(r < np) cout << -1 << nl;
        else if(n == 2) cout << -1 << nl;
        else{
            if(k <= n-2) cout << l << nl;
            else cout << np << nl;
        }
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