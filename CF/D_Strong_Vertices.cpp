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
    int n;
    cin >> n;
    int a[n],b[n];
    inp(a);
    inp(b);
    for(int i = 0; i < n; i++){
        a[i] = a[i] - b[i];
    }

    int mx = INT_MIN;
    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        vp.pb({a[i],i});
        mx = max(a[i],mx);
    }

    vector<int> sol;
    for(auto &[a,b] : vp) {
        if(a == mx) sol.pb(b+1);
    }
    
    cout << sol.size() << nl;
    for(auto &i : sol) cout << i << " "; 

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