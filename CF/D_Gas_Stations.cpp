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
#define lg(x)            (63 - __builtin_clzll(x))
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());

void solve(){
    int n, b, c;
    cin >> n >> b >> c;

    vector<int> x(n + 1), p(n + 1);
    for(int i = 1; i <= n; i++) cin >> x[i] >> p[i];

    vector<int> nxt(n + 1, 0), st;
    for(int i = n; i >= 1; i--){
        while(!st.empty() && p[st.back()] >= p[i]) st.pop_back();
        nxt[i] = st.empty() ? 0 : st.back();
        st.pb(i);
    }

    auto check = [&](int mid){
        int spent = 0;
        int fuel = 0;

        for(int i = 1; i <= n; ++i){
            if(mid <= x[i]) return true;

            int y = (i < n ? min(mid, x[i + 1]) : mid);
            int gap = y - x[i];
            if(gap > c) return false;

            int z = mid;
            if(nxt[i]) z = min(z, x[nxt[i]]);
            int need = max(0LL, min(c, z - x[i]));

            if(fuel < need){
                int buy = need - fuel;
                spent += buy * p[i];
                if(spent > b) return false;
                fuel = need;
            }

            fuel -= max(0LL, y - x[i]);
        }

        if(mid > x[n] && (mid - x[n]) > c) return false;
        return true;
    };


    int lo = 0, hi = x[n] + c, ans = 0;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(check(mid)){
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
