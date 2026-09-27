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

using pii = pair<int,int>;

void solve(){
    int s,q;
    cin >> s >> q;

    vector<pii> qry(q);

    for(int i = 0; i < q; i++){
        cin >> qry[i].ff >> qry[i].ss;
    }

    map<int,int> mp;

    for(int i = 1; i*i <= s; i++){
        if(s%i == 0){
            mp[i] = s/i;
            mp[s/i] = i;
        }
    }

    vector<int> x,y;

    for(auto &[a,b] : mp){
        x.pb(a);
        y.pb(b);
    }

    vector<int> cnt = y;

    for(int i = 1; i < cnt.size(); i++){
        cnt[i] = cnt[i] * (x[i] - x[i-1]);
    }


    vector<int> pre = cnt;
    prefixsum(pre);


    auto f = [&](int l){
        int val = 0;


        auto it = lower_bound(all(x), l);
        if(it == x.end() || *it > l) it = prev(it);


        int ind = it - x.begin();

        val += pre[ind];

        if(l > *it && next(it) != x.end()) val += (l - *it) * (y[ind+1]);

        return val;
    };

    auto ans = [&](pii &pr){
        int tot = 0;
        auto [l,h] = pr;

        
        tot += f(l);

        auto it = lower_bound(all(x),h);
        int ind = x.size() - 1 - (it - x.begin());

        
        tot -= f(min(x[ind],l));


        tot += h*(min(x[ind],l));

        cout << tot << nl;
    };


    for(auto &i : qry) ans(i);
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