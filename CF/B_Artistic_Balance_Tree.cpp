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
    inp(v);
    vector<int> a(m);
    inp(a);


    int tot = sm(v);

    multiset<int> o,e;

    bool op = false, ep = false;

    for(int i = 0; i < n; i++){
        if(i&1) e.insert(v[i]);
        else o.insert(v[i]);
    }

    for(auto &i : a){
        if(i&1) op = 1;
        else ep = 1;
    }

    int cnto = 0, cnte = 0;

    for(auto &i : a){
        if(i&1){
            if(o.size()){
                if(*(prev(o.end())) < 0) continue;
                else{
                    tot -= *(prev(o.end()));
                    o.erase((prev(o.end())));
                    cnto++;
                }
            }
        }
        else{
            if(e.size() && *(prev(e.end())) >= 0){
                tot -= *(prev(e.end()));
                e.erase((prev(e.end())));
                cnte++;
            }
        }
    }

    if(op && cnto == 0) tot -= *(prev(o.end()));
    if(ep && cnte == 0) tot -= *(prev(e.end()));

    cout << tot << nl;
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