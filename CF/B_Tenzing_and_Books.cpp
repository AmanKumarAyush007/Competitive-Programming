#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define setbit(x)  __builtin_popcountll(x)
#define sm(v)      accumulate(all(v),0LL)
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    inp(a);
    inp(b);
    inp(c);

    int curr = 0;

    for(int i = 0; i < n; i++){
        if((k|a[i]) != k) break;
        else curr |= a[i];
    }
    for(int i = 0; i < n; i++){
        if((k|b[i]) != k) break;
        else curr |= b[i];
    }
    for(int i = 0; i < n; i++){
        if((k|c[i]) != k) break;
        else curr |= c[i];
    }

    cout << ((k==curr) ? "Yes" : "No");
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