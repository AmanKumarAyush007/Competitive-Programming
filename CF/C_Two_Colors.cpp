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
    
    vector<int> a(k);
    inp(a);
    sort(all(a));

    int ans = 0;
    for(int i = 1; i < n; i++){
        int l = a.end() - lower_bound(all(a),i);
        int r = a.end() - lower_bound(all(a),n-i);

        if(l < r) swap(l,r);

        ans += l*r - r;
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