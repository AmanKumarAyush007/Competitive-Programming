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

    int mxsm = hell;
    int curr = 0;

    for(int i = 0; i < n-1; i++){
        curr += a[i];
        mxsm = max(mxsm,curr);
        if(curr < 0){
            curr = 0;
        }
    }

    curr = 0;
    for(int i = 1; i < n; i++){
        curr += a[i];
        mxsm = max(mxsm,curr);
        if(curr < 0){
            curr = 0;
        }
    }
    
    int sm = accumulate(a,a+n,0LL);

    cout << ((sm <= mxsm) ? "NO" : "YES");

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