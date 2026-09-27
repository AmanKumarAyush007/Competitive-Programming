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
    int n; cin >> n;
    vector<int> v(n);
    inp(v)

    map<int,int> mp;
    for(auto &i : v) mp[i]++;

    vector<int> ans;


    while(mp.size()){
        int lmt = inf;
        
        vector<int> temp;
        for(auto &[a,b] : mp){
            lmt = min(b,lmt);
            temp.pb(a);
        }

        sort(rall(temp));

        for(int i = 0; i < lmt; i++){
            for(auto &ele : temp) ans.pb(ele);
        }

        // debug(mp);
        // debug(temp, lmt);

        vector<int> trp;
        
        for(auto &[a,b] : mp){
            mp[a] -= lmt;
            if(mp[a] == 0) trp.pb(a);
        }

        for(auto &i : trp) mp.erase(i);

        // debug(mp);
        // debug(temp, lmt);
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