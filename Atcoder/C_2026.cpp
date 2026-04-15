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

set<int> val;

void precompute(int n){
    for(int i = 1; i*i <= n; i++){
        if(i*i > n) break;
        for(int j = i+1; j*j <= n; j++){
            if(i*i + j*j > n) break;
            val.insert(i*i + j*j);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    
    precompute(n);

    cout << val.size() << nl;
    for(auto &i : val) cout << i << " ";
    cout << nl;
    val.clear();
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}