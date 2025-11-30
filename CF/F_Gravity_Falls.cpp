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


using pi = pair<int,int>;


void solve(){
    int n;
    cin >> n;
    vector<vector<int>> v(n);

    int sz = 0;


    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        sz = max(sz,x);

        while(x--) {
            int e;
            cin >> e;
            v[i].pb(e);
        }
    }


    vector<int> ans;
    vector<vector<int>> vv = v;

    while(ans.size() < sz){

        sort(all(vv));
    
        for(auto &i : vv[0]) ans.pb(i);

        vv.clear();


        for(int i = 0; i < n; i++){
            int x = v[i].size();
    
    
            if(x > ans.size()){
                vector<int> tmp;
                for(int j = ans.size(); j < x; j++){
                    tmp.pb(v[i][j]);
                }
                vv.pb(tmp);
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