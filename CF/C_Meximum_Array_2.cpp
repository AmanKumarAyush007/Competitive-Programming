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

using pi = pair<int,int>;

void solve(){
    int n,k,q;
    cin >> n >> k >> q;

    vector<bool> o(n, 0), to(n,0);


    map<int,vector<pi>> mp;
    while(q--){
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        mp[t].pb({l,r});
        if(t == 1){
            for(int i = l; i <= r; i++){
                o[i] = 1;
            }
        }
        else{
            for(int i = l; i <= r; i++){
                to[i] = 1;
            }
        }
    }

    vector<int> ans(n,k);

    if(mp[1].size() == 0){
        for(int i = 0; i < n; i++){
            ans[i] = i % k;
        }
    }
    else if(mp[2].size()){
        for(int i = 0; i < n; i++){
            if(to[i] && o[i]) ans[i] = k+1;
        }

        for(auto &[a,b] : mp[2]){
            for(int i = a; i <= b; i++){
                if(ans[i] == k+1) continue;
                ans[i] = i % k;
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