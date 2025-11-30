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
#define lg(x)            (63 - __builtin_clzll(x)) // log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());

void solve(){
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> req(n);
    for(int i = 0; i < n; i++){
        cin >> req[i].ff >> req[i].ss;
    }

    int total = 0;
    int currt = 0, currp = 0;

    for(auto [a, b] : req){
        int x = a - currt;
        int P = abs(b - currp);

        int gap;
        if((x % 2) == (P % 2)) gap = x;
        else gap = x - 1;

        total += gap;
        currt = a;
        currp = b;
    }

    total += (m - currt);
    cout << total << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    if(!(cin >> t)) return 0;
    while(t--){
        solve();
    }
    return 0;
}
