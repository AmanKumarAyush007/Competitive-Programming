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

vector<int> sqr;

void solve(){
    int n;
    cin >> n;

    int ans = 4;
    int st = n*n;
    int en = (n+1)*(n+1);

    for(int i = 1; i*i < en; i++){
        int x = i*i;
        auto stit = lower_bound(sqr.begin() + i, sqr.end(), st - x);
        auto enit = prev(lower_bound(sqr.begin() + i, sqr.end(), en - x));

        int diff = enit - stit;

        if(diff < 0) continue;

        diff++;
        
        if(x == *stit) {
            diff--;
            ans += 4;
        }

        ans += diff*8;
    }

    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 1e5+5; i++){
        sqr.pb(i*i);
    }

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}