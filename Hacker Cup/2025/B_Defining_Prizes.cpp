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


void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int sum = 0, x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        sum += x;
    }

    sort(a.begin(), a.end(), greater<int>());

    vector<pair<int,int>> grp;
    for (int i = 0; i < n; ) {
        int v = a[i], c = 0;
        while (i < n && a[i] == v) {
            c++;
            i++;
        }
        grp.push_back({v, c});
    }

    int g = grp.size();
    int lo = 0, hi = g, ans = 0;

    auto ok = [&](int k) -> bool {
        if (k == 0) return true;
        if (k > m) return false;
        int need = 0;
        for (int j = 0; j < k; j++) {
            int give = k - j;
            if (give > m) return false;
            need += grp[j].second * give;
            if (need > sum) return false;
        }
        return need <= sum;
    };

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) {
            int cnt = 0;
            for (int j = 0; j < mid; j++) cnt += grp[j].second;
            ans = max(ans, cnt);
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << "\n";
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("C:/Users/desktop/Downloads/final/defining_prizes_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}