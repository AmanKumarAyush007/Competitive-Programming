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
    int a,b,g;
    cin >> a >> b >> g;
    int l = (a+g-1)/g;      //ceil
    int r = b/g;            //floor

    int ans = 0;
    
    for(int len = r-l; len >= 0; len--){
        for(int i = l; i <= r-len; i++){
            if(gcd(i,i+len) == 1){
                cout << g*i << " " << g*(i+len) << nl;
                return;
            }
        }
    }

    cout << -1 << " " << -1;
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