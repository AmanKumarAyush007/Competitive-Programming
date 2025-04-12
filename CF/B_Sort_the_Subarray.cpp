#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)



void solve(){
    int n;
    cin >> n;
    int a[n],b[n];
    inp(a)
    inp(b)

    int l = 0;
    int r = n-1;

    while(l < n && a[l] == b[l]) l++;
    while(r >= 0 &&  a[r] == b[r]) r--;

    int mn = inf;
    int mx = hell;

    for(int i = l; i <= r; i++){
        mn = min(mn,b[i]);
        mx = max(mx,b[i]);
    }

    while(l > 0 && a[l-1] <= mn) {
        mn = min(mn,a[l-1]);
        l--;
    }
    while(r < n-1 && a[r+1] >= mx) {
        mx = max(mx,a[r+1]);
        r++;
    }
    
    cout << l+1 << " " << r+1;
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