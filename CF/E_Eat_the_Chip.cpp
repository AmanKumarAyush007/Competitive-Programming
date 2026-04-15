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
    int n, m, xa, ya, xb, yb;
    cin >> n >> m >> xa >> ya >> xb >> yb;

    
    if(xa >= xb) cout << "Draw";
    else{
        int mx = max(xb - xa, abs(ya - yb));


        if(mx&1){
            if(yb == ya) cout << "Alice";
            else {
                int by = (yb > ya) ? min((yb + mx/2), m) : max((yb - mx/2), 1LL);
                int bx = max(1LL, xb - mx/2);

                int ay = (yb > ya) ? min((ya + mx/2), m) : max((ya - mx/2), 1LL);
                int ax = min(n, xa + mx/2);

                if((ax+1 == bx) && (ay == by || ay+1 == by || ay-1 == by)) cout << "Alice";
                else cout << "Draw";
            }
        }
        else{
            if(yb == ya) cout << "Bob";
            else {
                int by = (yb < ya) ? min((yb + mx/2), m) : max((yb - mx/2), 1LL);
                int bx = max(1LL, xb - mx/2);

                int ay = (yb < ya) ? min((ya + mx/2), m) : max((ya - mx/2), 1LL);
                int ax = min(n, xa + mx/2);

                if(ax == bx && ay == by) cout << "Bob";
                else cout << "Draw";
            }
        }
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