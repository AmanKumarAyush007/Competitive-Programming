#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,m;
    cin >> n >> m;
    int b[n],g[m];
    for(auto &i : b) cin >> i;
    for(auto &i : g) cin >> i;

    sort(b,b+n);
    sort(g,g+m);


    if(b[n-1] > g[0]) {
        cout << -1 << nl;
        return;
    }

    int ans = accumulate(g,g+m,0);
    for(int i = 0; i < n-1; i++){
        ans += b[i]*m;
    }


    if(b[n-1] != g[0]){
        ans += b[n-1];
        ans -= b[n-2];
    }

    cout << ans;
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}