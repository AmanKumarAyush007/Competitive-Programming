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
    vector<int> a(n),b(n);
    inp(a)
    inp(b)

    sort(all(a));
    sort(all(b));


    int ans = 1;

    for(int i = 0; i < n; i++){
        auto it = lower_bound(all(b),a[i]);
        ans = (ans * ((it-b.begin()) - i)) % (1000000007);
    }

    cout << ans;
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