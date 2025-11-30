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


void solve()
{
    int n;
    cin >> n;

    unordered_map<int, vector<int>> mp;

    vector<int> a(n), b(n);
    inp(a);
    inp(b);

    for (int i = 0; i < n; i++){
        mp[a[i]].pb(b[i]);
    }

    // debug(mp);

    int mx = 0;
    for (auto &[c, v] : mp){
        sort(rall(v));
        int x = v.size();
        mx = max(mx, x);
    }

    vector<vector<pair<int, int>>> s(mx + 1), t(mx + 1);

    for (auto &[c, v] : mp){

        int sz = v.size();

        prefixsum(v);

        // debug(v);

        for (int i = 1; i <= sz; i++){
            s[i].pb({v[i - 1], c});
            if (i <= sz - 1) t[i].pb({v[i], c});
        }
    }

    int ans = 0;

    for (int m = 1; m <= mx; m++){
        int s1 = -hell, s2 = -hell;
        
        int c1 = -1, c2 = -1;

        for (auto &[val,c] : s[m]){
            if (val > s1){
                s2 = s1;
                c2 = c1;
                s1 = val;
                c1 = c;
            }
            else if (val > s2){
                s2 = val;
                c2 = c;
            }
        }

        if (s2 != -inf) ans = max(ans, s1 + s2);
            
        if (!t[m].empty() && s1 != -inf){

            for (auto &[t,u] : t[m]){
                int x = (u == c1 ? s2 : s1);
                if (x == -inf) continue;
                ans = max(ans, t + x);
            }
        }
    }

    cout << ans << nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
