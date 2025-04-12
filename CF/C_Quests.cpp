#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x
#define sm(v)      accumulate(all(v),0LL)


void solve(){
    int n,k;
    cin >> n >> k;
    int a[n],b[n];
    inp(a);
    inp(b);
    int pre[n],mx[n];

    pre[0] = a[0];
    mx[0] = b[0];
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + a[i];
        mx[i] = max(mx[i-1],b[i]);
    }

    int ans = INT_MIN;

    for(int i = 0; i < min(k,n); i++){
        int val = pre[i] + mx[i]*(k-(i+1));
        ans = max(ans,val);
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