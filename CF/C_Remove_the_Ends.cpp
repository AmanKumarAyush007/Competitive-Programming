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
    vector<int> v(n);
    inp(v);

    int pre[n], suff[n];
    pre[0] = max(0LL,v[0]), suff[n-1] = abs(min(0LL,v[n-1]));

    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + max(0LL,v[i]);
    }
    for(int i = n-2; i >= 0; i--){
        suff[i] = suff[i+1] + abs(min(0LL,v[i]));
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans = max(ans,pre[i]+suff[i]);
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