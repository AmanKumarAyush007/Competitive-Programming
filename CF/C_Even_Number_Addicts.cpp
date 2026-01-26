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

bool rec(vector<bool>& dp, int i, int od, int ev,int A){
    if(i == dp.size()) return (A%2 == 0);

    bool res = 1;
    
    if(i%2 == 0){
        if(od > 0) res &= rec(dp,i+1,od-1,ev,A+1);
        if(ev > 0) res &= rec(dp,i+1,od,ev-1,A);
    }
    else{
        if(od > 0) res &= rec(dp,i+1,od-1,ev,A);
        if(ev > 0) res &= rec(dp,i+1,od,ev-1,A);
    }

    return dp[i] = res;
}


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    int cnto = 0, cnte = 0;

    for(auto &i : v) {
        if(i&1) cnto++;
        else cnte++;
    }

    vector<bool> dp(n,false);

    bool ans = rec(dp,0,cnto,cnte,0);

    cout << (ans ? "Alice" : "Bob") << nl;
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