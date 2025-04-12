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
    int a[n];
    inp(a);
    if(n == k){
        for(int i = 1; i < n; i += 2){
            if(a[i] != i/2 + 1) {
                cout << i/2 + 1 << nl;
                return;
            }
        }
        cout << n/2 + 1 << nl;
    }
    else {
        for(int i = 1; i <= n-k+1; i++){
            if(a[i] != 1){
                cout << 1 << nl;
                return;
            }
        }
        cout << 2 << nl;
    }

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