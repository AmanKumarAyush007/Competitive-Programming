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
    int n,m;
    cin >> n >> m;
    int fab[n+1];
    fab[0] = 0;
    fab[1] = 1;
    fab[2] = 2;
    for(int i = 3; i <= n; i++){
        fab[i] = fab[i-1] + fab[i-2];
    }
    while(m--){
        int w,l,h;
        cin >> w >> l >> h;
     
        if((h >= fab[n] + fab[n-1]) && l >= fab[n] && w >= fab[n]) cout << 1;
        else if((w >= fab[n] + fab[n-1]) && h >= fab[n] && l >= fab[n]) cout << 1;
        else if((l >= fab[n] + fab[n-1]) && w >= fab[n] && h >= fab[n])cout << 1;
        else cout << 0;
    }
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