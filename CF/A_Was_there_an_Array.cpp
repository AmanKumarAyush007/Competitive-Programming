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
    int a[n-2];
    inp(a);
    // cout << n;
    if(n - 2 < 3) {
        cout << "YES" << nl;
        return;
    }
    for(int i = 0; i < n-2-2; i++){
        if((a[i] == 1) && (a[i+1] == 0) && (a[i+2] == 1)){
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