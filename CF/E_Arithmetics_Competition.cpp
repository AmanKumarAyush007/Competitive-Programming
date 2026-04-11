#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
#define debug(x...)
#endif
#define int              int64_t
#define ff               first
#define ss               second
#define pb               push_back
#define inf              (int)1e18
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());



void solve(){
    int n,m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m);
    inp(a);
    inp(b);

    sort(rall(a));
    sort(rall(b));

    vector<int> pa(n+1), pb(m+1);
    for(int i = 0; i < n; i++){
        pa[i+1] = pa[i] + a[i];
    }
    for(int i = 0; i < m; i++){
        pb[i+1] = pb[i] + b[i];
    }


    vector<pair<int,int>> vp(n+m+1);

    int l = 0, r = 0;

    for(int i = 1; i < n+m+1; i++){
        if(l < n && r < m){
            if(a[l] < b[r]) r++;
            else l++;
        }
        else if(l == n) r++;
        else if(r == m) l++;

        vp[i] = {l,r};
    }


    while(q--){
        int x,y,z;
        cin >> x >> y >> z;

        auto [A, B] = vp[z];

        int ans = 0;

        if(A > x) ans = pa[x] + pb[z - x];
        else if(B > y) ans = pa[z-y] + pb[y];
        else ans = pa[A] + pb[B];

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