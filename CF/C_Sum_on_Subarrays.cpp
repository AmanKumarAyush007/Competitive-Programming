#include<bits/stdc++.h>
using namespace std;

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


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n,k;
    cin >> n >> k;

    vector<int> v(n);

    iota(rall(v),1);
    prefixsum(v);
    debug(v);

    auto it = lower_bound(all(v),k);

    int ind = it - v.begin();

    vector<int> ans(n);

    if(*it == k){
        for(int i = 0; i < n; i++){
            if(i <= ind) ans[i] = 1000;
            else ans[i] = -1;
        }
    }
    else{
        for(int i = 0; i < ind; i++){
            ans[i] = 1000;
        }

        int req = (ind > 0 ? k - v[ind-1] : k);
        int lt = req;

        int i = ind;
        if(req){
            debug(ind,req);
            ans[ind] = req + 1;
            req--;
            i++;
        } 
        while(req--){
            ans[i] = -1;
            i++;
        }
        while(i < n) {
            ans[i] = -lt-2;
            i++;
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