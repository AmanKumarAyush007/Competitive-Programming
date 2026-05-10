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
#define nl               endl
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());

int ask(int x, int y){
    cout << "? " << x << " " << y << nl;
    int res;
    cin >> res;
    return res;
}

void solve(){
    int ans = 1;
    int hi = 1000, lo = 1;

    while(hi >= lo){
        int mid = (lo+hi)/2;

        int val = ask(mid, mid+1);

        if(val == mid*(mid+1)){
            lo = mid + 1;
        }
        else if(val == (mid+2)*(mid+1)) hi = mid - 1;
        else {
            cout << "! " << mid+1 << nl;
            return;
        }
    }

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