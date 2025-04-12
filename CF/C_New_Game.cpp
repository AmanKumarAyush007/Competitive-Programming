#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    inp(a);
    // sort(a,a+k);
    sort(all(a));
    int r = 0;
    int ans = 0;
    for(int l = 0; l < n; l++){
        r = max(l,r);
        while((r+1 < n) && (a[r+1] - a[r] <= 1) && (a[r+1] - a[l] < k)) r++;
        ans = max(ans,r-l+1);
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