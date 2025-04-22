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
    int n,k;
    cin >> n >> k;
    int a[n],b[n];
    inp(a)
    inp(b)

    int c[n];
    int ans = 0;

    for(int i = 0; i < n; i++){
        c[i] = min(a[i],b[i]);
        ans += max(a[i],b[i]);
    }
    sort(c,c+n,greater<int>());

    for(int i = 0; i < n && i < k-1; i++){
        ans += c[i];
    }

    ans++;

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