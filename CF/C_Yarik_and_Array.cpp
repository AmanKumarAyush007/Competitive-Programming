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
    int n;
    cin >> n;
    int a[n];
    inp(a);
    
    int curr = a[0];
    int ans = curr;
    for(int i = 1; i < n; i++){
        if((abs(a[i])&1) == (abs(a[i-1])&1)) curr = a[i];
        else curr += a[i];
        if(a[i] > curr) curr = a[i];
        ans = max(curr,ans);
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