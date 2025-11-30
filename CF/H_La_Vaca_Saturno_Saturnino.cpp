#include <bits/stdc++.h>
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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> ans(m + 1, 0);
    vector<bool> seen(m + 1, false);

    for (int t = 0; t < n; t++) {
        int x;
        cin >> x;
        vector<int> v(x);
        inp(v)

        vector<bool> nwt(x, false);
        for (int j = 0; j < x; j++) {
            if (!seen[v[j]]) nwt[j] = true;
        }

        bool suffpres = true;
        for (int j = x - 1; j >= 0; j--) {
            if (!nwt[j]) {
                suffpres = false;
            } else {
                if (!suffpres) {
                    ans[v[j]] = 1; 
                }
            }
        }

        for (int j = 0; j < x; j++) {
            if (nwt[j]) seen[v[j]] = true;
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
