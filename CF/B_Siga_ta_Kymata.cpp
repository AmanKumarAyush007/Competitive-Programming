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
#define all(a)           (a).begin(), (a).end()
#define rall(a)          (a).rbegin(), (a).rend()
#define sm(v)            accumulate(all(v), 0LL)
#define inp(v)           for (auto &x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) // log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);
    string x;
    cin >> x;


    if (x[0] == '1' || x[n - 1] == '1') {
        cout << -1 << nl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (x[i] == '1' && (v[i] == 1 || v[i] == n)) {
            cout << -1 << "\n";
            return;
        }
    }

    auto oneind = find(all(v),1) - v.begin();
    auto nind = find(all(v),n) - v.begin();

    cout << 5 << nl;
    cout << 1 << " " << oneind + 1 << nl;
    cout << 1 << " " << nind+1 << nl;
    cout << oneind+1 << " " << n << nl;
    cout << nind+1 << " " << n << nl;
    cout << min(oneind,nind)+1 << " " << max(oneind,nind)+1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
