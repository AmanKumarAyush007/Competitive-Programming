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

using pi = pair<int,int>;

void solve(){
    int n, m; 
    cin >> n >> m;

    vector<int> v(n);
    inp(v);

    map<pi,vector<array<int,3>>> mp;

    for(int i = 0; i < m; i++){
        int s,d,k;
        cin >> s >> d >> k;

        mp[{d, s%d}].pb({s, k, i});
    }

    vector<int> ans(m);

    for(auto &[pr, vec] : mp){
        auto [d, r] = pr;
        r %= d;

        if(r == 0) r = d;

        vector<int> pre, sum;

        for(int i = r; i <= n; i += d){
            pre.pb(v[i-1]);
            sum.pb(v[i-1]);
        }

        for(int i = 1; i < pre.size(); i++) pre[i] += pre[i-1];
        for(int i = 1; i < sum.size(); i++) sum[i] = (i+1)*sum[i] + sum[i-1];

        for(auto &[s,k,i] : vec){
            int st = (s - r)/d;
            int en = st + k - 1;

            ans[i] = sum[en];

            if(st) ans[i] -= sum[st - 1] + (st * (pre[en] - pre[st-1]));
        }
    }


    for(auto &i : ans) cout << i << " ";
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