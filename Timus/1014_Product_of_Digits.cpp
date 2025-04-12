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
    if(n == 0){ 
        cout <<  10;    // ans must be +ve number hence 0 cant be ans
        return;
    }
    if(n == 1){
        cout << 1;
        return;
    }
    int r = n;
    vector<pair<int,int>> vp;
    for(int i = 9; i >= 2; i--){
        int cnt = 0;
        while(n > 0 && n%i == 0){
            cnt++;
            n /= i;
        }
        vp.pb({i,cnt});
    }
    sort(all(vp));
    int k = 1;
    for(auto [a,b] : vp){
        while(b--) k *= a;
    }
    if(k != r) {
        cout << -1;
        return;
    }
    for(auto &[a,b] : vp){
        while(b--) cout << a;
    }
    
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