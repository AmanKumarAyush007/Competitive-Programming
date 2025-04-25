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

bool check(vector<pair<int,int>> &vp, int mid){
    int n = vp.size();
    int  l = 0, r = 0;
    for(int i = 0; i < n; i++){
        l = max(l - mid, vp[i].ff);
        r = min(r + mid, vp[i].ss);
        if(l > r) return false;
    }
    return true;
}


void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        vp.pb({x,y});
    }

    int hi = 1e10, lo = 0, ans = 0;;

    while(hi >= lo){
        int mid = hi - ((hi - lo)/2);
        if(check(vp,mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
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