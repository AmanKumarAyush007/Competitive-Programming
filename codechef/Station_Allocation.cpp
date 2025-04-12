#include<bits/stdc++.h>
using namespace std;

#define int        long long
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
    vector<int> v(n);
    inp(v)
    sort(all(v));

    int tot = sm(v);

    int q;
    cin >> q;

    while(q--){
        int x,y;
        cin >> x >> y;

        int ans = 0;

        auto it = lower_bound(all(v),x);
        if(it == v.end()) {
            ans += x - v[n-1];
            int rest = tot - v[n-1];
            ans += max(0LL,y - rest);
        }
        else {
            int rest = tot - *it;
            ans += max(0LL,y - rest);
            if(it - v.begin() >= 1) {
                it--;
                int ex = x - *it;
                int rest = tot - *it;
                ex += max(0LL,y - rest);
                ans = min(ans,ex);
            }
        }
        
        cout << ans << nl;
    }
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