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
    int n;
    cin >> n;
    int a[n];
    inp(a)
    
    int o = count(a,a+n,2);
    int e = count(a,a+n,1);
    if(e == 0) e = INT_MAX;
    else e = 0;

    for(int i = 0; i < n; ){
        if(a[i] == 1 && i < n-1 && (a[i] == a[i+1])) {
            e++;
            i += 2;
        }
        else {
            if(a[i] == 1) e++;
            i++;
        }
        // cout << i << e << nl;
    }
    // cout << o << " " << e;
    cout << min(o,e);
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