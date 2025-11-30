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
    int n;
    cin >> n;

    vector<int> v(n);
    iota(all(v),1);

    set<int> st(all(v));

    vector<int> ans;

    bool ev = true;
    while(st.size() > 0){
        int curr = 0;
        auto it = st.begin();

        vector<int> ap;
        while(it != st.end()){
            bool ck = curr & 1;
            if(!ev) ck = !ck;
            if(ck){
                ap.pb(*it);
            }
            curr++;
            it++;
        }

        if(st.size() % 2) ev = !ev;
        for(auto &i : ap){
            st.erase(i);
            ans.pb(i);
        }
    }


    for(auto &i : ans) cout << i << " ";

    cout << nl;
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