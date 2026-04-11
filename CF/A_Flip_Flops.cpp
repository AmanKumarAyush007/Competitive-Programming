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
    int n, c, k;
    cin >> n >> c >> k;

    multiset<int> ms;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ms.insert(x);
    }


    while(ms.size()){
        auto it = prev(ms.end());

        while(it != ms.begin() && *it > c){
            it = prev(it);
        }

        if(it == ms.begin() && *it > c) break;

        int x = *it;
        ms.erase(it);  

        int can = c - x;

        x += min(k, can);

        k -= min(k , can);

        c += x;
    }


    cout << c << nl;
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