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
    int n,m;
    cin >> n >> m;
    
    vector<int> v(n);
    vector<vector<int>> mat(n, vector<int>(m));

    inp(v);
    for(int i = 0; i < n; i++){
        inp(mat[i]);
    }

    
    vector<int> req = v;
    for(int i = 1; i < n; i++){
        req[i] = min(req[i], req[i-1]);
    }

    
    auto pre = mat;
    multiset<int,greater<>> ms;

    for(int i = n-1; i >= 0; i--){
        for(auto &j : mat[i]) ms.insert(j);
        while(ms.size() > m) ms.erase(prev(ms.end()));

        pre[i] = vector<int>(all(ms));

        prefixsum(pre[i]);
    }



    int ans = m;
    for(int i = 0; i < n; i++){
        auto it = lower_bound(all(pre[i]), req[i]);
        if(it != pre[i].end()) ans = min(ans, 1+(it - pre[i].begin()));
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