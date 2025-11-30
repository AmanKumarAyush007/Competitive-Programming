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



void solve(){
    int n,k;
    cin >> n >> k;
    multiset<int> pq;
    multiset<int,greater<int>> cst;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cst.insert(x);
    }

    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        pq.insert(x);
    }

    int ans = 0;

    while(cst.size() && pq.size()){
        int sz = *pq.begin();
        if(sz > cst.size()) break;

        // for(auto &i : pq) cout << i << " " ;
        // cout << nl;
        // for(auto &i : cst) cout << i << " " ;
        // cout << nl;

        sz--;

        while (sz >= 0 && !cst.empty()) {
            auto it = cst.begin();
            if (sz > 0) ans += *it;
            cst.erase(it);
            sz--;
        }
        
        pq.erase(pq.begin());
    }

    ans += sm(cst);
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