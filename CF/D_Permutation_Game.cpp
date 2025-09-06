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
    int n,k,pb,ps;
    cin >> n >> k >> pb >> ps;

    pb--, ps--;

    vector<int> p(n), a(n);
    for(auto &i : p) cin >> i, i--;

    inp(a)

    int cnt = min(k,n);
    int in = pb;
    int bad = 0, curr = 0, i = 1;
    
    while(cnt--){
        curr += a[in];
        bad = max(bad,curr + (a[in] * (k-i)));
        in = p[in];
        i++;
    }

    cnt = min(k,n);
    in = ps;
    curr = 0, i = 1;
    int sas = 0;

    
    while(cnt--){
        curr += a[in];
        sas = max(sas,curr + (a[in] * (k-i)));
        in = p[in];
        i++;
    }

    if(sas == bad) cout << "Draw";
    else if(sas > bad) cout << "Sasha";
    else cout << "Bodya";

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