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
    vector<int> a(n);
    inp(a);
    int ans = 0;

    if(k == 1){
        for(int i = 1; i < n-1; i++){
            ans = max(ans,max(a[i]+a[0],a[i]+a[n-1]));
        }
        ans = max(ans,a[0]+a[n-1]);
    }
    else{
        sort(all(a),greater<int>());
        
        for(int i = 0; i <= k; i++){
            ans += a[i];
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