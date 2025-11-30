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
#define rall(a)          (a).rbegin(),(a).r end()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());

void solve(){
    int n; 
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; ++i) cin >> a[i];

    int S = 0;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) S += a[i];
        else S -= a[i];
    }

    int ans = S;

    int first_odd = -1, last_odd = -1, first_even = -1, last_even = -1;

    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            if (first_odd == -1) first_odd = i;
            last_odd = i;
        } else {
            if (first_even == -1) first_even = i;
            last_even = i;
        }
    }

    if (first_odd != -1 && last_odd > first_odd) 
        ans = max(ans, S + (last_odd - first_odd));
    if (first_even != -1 && last_even > first_even) 
        ans = max(ans, S + (last_even - first_even));

    int min_odd_expr = inf; 
    int max_even_expr = hell;

    for (int j = 1; j <= n; ++j) {
        if (j & 1) {
            if (max_even_expr != hell) {
                int cur = max_even_expr - (2*a[j] - j);
                ans = max(ans, S + (int)cur);
            }
            min_odd_expr = min(min_odd_expr, (int)j + 2*(int)a[j]);
        } else {
            if (min_odd_expr != inf) {
                int cur = ( (int)j + 2*(int)a[j] ) - min_odd_expr;
                ans = max(ans, S + (int)cur);
            }
            max_even_expr = max(max_even_expr, 2*(int)a[j] - (int)j);
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
