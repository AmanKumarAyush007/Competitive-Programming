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
    vector<int> v(n);
    inp(v)

    vector<int> req;
    vector<int> ind;


    for(int i = 0; i < n; i++){
        if(v[i] < i+1) {
            req.pb(v[i]);
            ind.pb(i+1);
        }
    }

    sort(all(req));
    sort(all(ind));

    int ans = 0;

    for(int i = 0; i < ind.size(); i++){
        auto it = upper_bound(all(req),ind[i]);
        if(it == req.end()) break;
        else ans += (req.end() - it);
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