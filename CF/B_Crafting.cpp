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
#define inp(v)     for(auto& x : v) cin >> x
#define setbit(x)  __builtin_popcountll(x)


void solve(){
    int n;
    cin >> n;
    int a[n],b[n];
    inp(a);
    inp(b);

    int ans = 0;
    int ind = 0;

    for(int i = 0; i < n; i++){
        if(b[i]-a[i] > 0) {
            ans++;
            ind = i;
        }
    }

    if(ans == 0) cout << "YES";
    else if(ans == 1) {
        int mn = inf;
        for(int i = 0; i < n; i++){
            if(i != ind) mn = min(mn,a[i]-b[i]);
        }
        if(b[ind] - a[ind] > mn) cout << "NO";
        else cout << "YES";
    }
    else cout << "NO";
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