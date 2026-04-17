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
    int n;
    cin >> n;

    vector<int> a(n), d(n);
    inp(a);
    inp(d);

    set<int> ms;
    for(int i = 0; i < n; i++) ms.insert(i);

    vector<int> ans(n,0);

    set<int> cur;
    for(int i = 0; i < n; i++) cur.insert(i);

    for(int i = 0; i < n; i++){
        if(ms.size() <= 1) break;

        vector<int> tmp;
        set<int> nxt; 

        for(auto &idx : cur){
            if(!ms.count(idx)) continue;

            auto it = ms.find(idx);

            int att = 0;
            if(it != ms.begin()) att += a[*prev(it)];
            if(next(it) != ms.end()) att += a[*next(it)];

            if(d[idx] < att) tmp.pb(idx);
        }

        if(tmp.empty()) break;

        ans[i] = tmp.size();

        for(auto &j : tmp){
            auto it = ms.find(j);

            int L = -1, R = -1;
            if(it != ms.begin()) L = *prev(it);
            if(next(it) != ms.end()) R = *next(it);

            ms.erase(j);

            if(L != -1) nxt.insert(L);
            if(R != -1) nxt.insert(R);
        }

        cur = nxt; 
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