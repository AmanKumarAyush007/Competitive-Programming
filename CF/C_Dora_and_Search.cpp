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
    int n; cin >> n;
    int a[n];
    inp(a);
    int l = 0, r = n-1;
    int mx = *max_element(a,a+n);
    int mn = *min_element(a,a+n);
    bool done = false;

    while(l <= r){
        if(a[l] != mn && a[l] != mx && a[r] != mn && a[r] != mx ) {
            done = true;
            break;
        }
        if(a[l] == mn){
            mn++;
            l++;
        }
        else if(a[l] == mx){
            mx--;
            l++;
        }
        if(a[r] == mn){
            mn++;
            r--;
        }
        else if(a[r] == mx){
            mx--;
            r--;
        }        
    }
    if(done) cout << l+1 << " " << r+1;
    else cout << -1;

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