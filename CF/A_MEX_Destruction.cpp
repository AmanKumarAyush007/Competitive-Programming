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
    bool ck = true;
    for(auto &i : a){
        if(i != 0){
            ck = false;
            break;
        }
    }
    int ans = 0;
    if(!ck){
        ans= 1;
        int st = 0, en = 0;
        for(int i = 0; i < n; i++){
            if(a[i] != 0) {
                st = i;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(a[i] != 0) en = i;
        }

        for(int i = st; i <= en; i++){
            if(a[i] == 0) ans = 2;
        }
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