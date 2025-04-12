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
    for(int i = 0; i < 34; i++){
        if((1LL << i) == n || ((1LL << i)-1 == n) ) {
            cout << -1 << nl;
            return;
        }

    }
    for(int i = 1; i < n; i++){
        int x = i^n;
        if(i+x > n && n+i > x && n+x > i) {
            cout << i << nl;
            return;
        }
        x = n^(n-i);
        if((n-i)+x > n && n+(n-i) > x && n+x > (n-i)) {
            // cout << " !!";
            cout << n-i << nl;
            return;
        }
    }
    cout << -1 << nl;
    
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