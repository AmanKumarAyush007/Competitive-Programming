#include<bits/stdc++.h>
using namespace std;

#define int              int64_t
#define ff               first
#define ss               second
#define pb               push_back
#define inf              LLONG_MAX
#define hell             LLONG_MIN
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)    partial_sum(all(a), (a).begin());
#define suffixsum(a)    partial_sum(rall(a), (a).rbegin());


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> vp(m);

    for(int i = 0; i < m; i++){
        cin >> vp[i].ff;
        cin >> vp[i].ss;
    }

    int q;
    cin >> q;

    vector<int> v(q);
    inp(v);

    int lo = 0;
    int hi = q-1;
    int ans = -1;

    auto check = [&](int x){
        vector<int> cnt(n+1);

        for(int i = 0; i <= x; i++){
            cnt[v[i]] = 1;
        }

        prefixsum(cnt);

        for(int i = 0; i < m; i++){
            int u = vp[i].ss;
            int l = vp[i].ff;

            int o = cnt[u] - cnt[l-1];
            int z = u - l + 1 - o;

            if(o > z) return true;

        }

        return false;
    };

    while(lo <= hi){
        int mid = (hi + lo) / 2;
        if(check(mid)){
            hi = mid - 1;
            ans = mid;
        }
        else lo = mid + 1;
    }

    if(ans != -1) ans++;

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