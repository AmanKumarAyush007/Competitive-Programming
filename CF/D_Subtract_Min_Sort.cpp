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
    int a[n];
    inp(a);
    for(int i = 0; i < n-1; i++){
        int k = min(a[i],a[i+1]);
        a[i] -= k;
        a[i+1] -= k;
        if(a[i] != 0){
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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