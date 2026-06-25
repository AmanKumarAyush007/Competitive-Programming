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
    int n;
    cin >> n;

    vector<int> v(n);
    inp(v);

    vector<vector<bool>> lft(n+1, vector<bool>(n+1));

    int ans = 0;
    for(int i = 0; i < n; i++){
        vector<bool> vis(n+1);
        int mx = -inf, mn = inf;

        for(int j = i; j < n; j++){
            if(vis[v[j]]) break;

            vis[v[j]] = 1;

            mx = max(mx, v[j]);
            mn = min(mn, v[j]);

            int len = j - i + 1;

            if(mx - mn + 1 == len){
                if(mx + len <= n && lft[mx+1][mx+len]){
                    ans = max(ans, len);
                }
                if(mn - len >= 0 && lft[mn-len][mn-1]){
                    ans = max(ans, len);
                }
            }
        }


        vis.assign(n+1, false);
        mx = -inf, mn = inf;

        for(int j = i; j >= 0; j--){
            if(vis[v[j]]) break;

            vis[v[j]] = 1;
            
            mx = max(mx, v[j]);
            mn = min(mn, v[j]);

            int len = i - j + 1;

            if(mx - mn + 1 == len){
                lft[mn][mx] = 1;
            }
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