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
#define inf              LLONG_MAX
#define hell             LLONG_MIN
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
    int n,m;
    cin >> n >> m;
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int wt = x2-x1;
    int ht = y2 - y1;

    int w,h;
    cin >> w >> h;

    if(ht + h > m && wt + w > n) cout << -1 ;
    else{
        int ans = inf;

        if(ht + h <= m){
            int up = m - y2;
            int down = y1;
            int req = h;
            int upreq = max(0LL,req-up);
            int downreq = max(0LL,req - down);
            ans = min(ans,min(upreq,downreq));
        }

        if(wt + w <= n){
            int r = n - x2;
            int l = x1;
            int req = w;
            int rreq = max(0LL,req - r);
            int lreq = max(0LL, req - l);
            ans = min(ans,min(rreq,lreq));
        }

        double k = ans;

        cout << fixed << setprecision(9) << k;

    }


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