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

vector<int> v;


void solve(){
    int n;
    cin >> n;
    if(n == 1) {
        cout << "YES\n";
        return;
    }
    while(n > 0){
        int k = n;
        for(int i = v.size() - 1; i > 0; i--){
            if(n%v[i] == 0) {
                n /= v[i];
                break;
            }
        }
        if (k == n) {
            cout << ((n == 1) ? "YES\n" : "NO\n");
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
    int i = 0;
    v.pb(1);
    while(v.size() < 32){
        int k = v.size();
        for(  ;i < k; i++){
            int ele = v[i]*10;
            v.pb(ele);
            v.pb(ele+1);
        }
    }
    while(t--){
        solve();
    }
    return 0;
}