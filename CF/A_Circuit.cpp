#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    int a[2*n];
    for(auto &i : a) cin >> i;
    int cnt = 0;

    for(int i = 0; i < 2*n; i++){
        if(a[i] == 1) cnt++;
    }

    int mn = cnt%2;
    int mx = (cnt<=n) ? cnt : n - (cnt - n);
    cout<< mn  << " " << mx << nl;
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