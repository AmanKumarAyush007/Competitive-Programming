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
    int a[4];
    inp(a);
    map<int,int> mp;
    mp[a[0] + a[1]]++;
    mp[a[2] - a[1]]++;
    mp[a[3] - a[2]]++;

    int ans = INT_MIN;
    for(auto &[a,b] : mp) ans = max(b,ans);

    cout << ans;
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