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
    int n, m;
    cin >> n >> m;

    vector<int> type(n), val(n), start(n), sz(n);
    for(int i = 0; i < n; i++){
        cin >> type[i] >> val[i];
    }

    start[0] = sz[0] = 1;

    for(int i = 1; i < n; i++){
        start[i] = sz[i-1] + 1;

        if(type[i] == 1) sz[i] = sz[i-1] + 1;
        else {
            if(sz[i-1] > (int)2e18 / (1 + val[i])) sz[i] = (int)2e18;
            else sz[i] = sz[i-1] * (1 + val[i]);
        }
    }

    vector<int> t1, tind;

    for(int i = 0; i < n; i++){
        if(type[i] == 1) {
            t1.pb(start[i]);
            tind.pb(i);
        }
    }


    auto query = [&](int ind){

        while(true){
            auto it = lower_bound(all(t1), ind);
            if(it == t1.end() || *it != ind) {
                it = prev(it);
                int k = *it;
                ind = ind % k;

                if(ind == 0) return val[tind[it - t1.begin()]];
            }
            else return val[tind[it - t1.begin()]];
        }
    };


    while(m--) {
        int x;
        cin >> x;
        cout << query(x) << " ";
    }

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