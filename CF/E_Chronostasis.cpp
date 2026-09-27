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

    vector<int> v(n);
    inp(v);

    multiset<int> po,ne;

    for(auto &i : v) {
        if(i < 0) ne.insert(i);
        else po.insert(i);
    }


    if(po.size() == 0 || *prev(po.end()) == 0){
        cout << -1 << nl;
        return;
    }

    vector<int> ans;

    auto it = po.begin();

    while(*it == 0) it = next(it);

    ans.pb(*it);
    po.erase(it);


    while(true){
        if(po.size() == 0 && ne.size() == 0){
            break;
        }
        auto ubnd = ne.upper_bound(-ans.back());
        if(ubnd != ne.end()){
            ans.pb(ans.back() + *ubnd);
            ne.erase(ubnd);
        }
        else{
            if(po.size()) {
                ans.pb(ans.back() + *po.begin());
                po.erase(po.begin());
            }
            else {
                cout << -1 << nl;
                return;
            }
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