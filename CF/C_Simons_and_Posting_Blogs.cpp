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
    vector<vector<int>> v(n, vector<int>());
    for(int i = 0; i < n; i++){
        int sz;
        cin >> sz;

        for(int j = 0; j < sz; j++){
            int x;
            cin >> x;
            if(v[i].size() && x == v[i].back()) continue;
            v[i].pb(x);
        }

        reverse(all(v[i]));
    }

    vector<int> ans;
    set<int> st;

    sort(all(v));

    for(int i = 0; i < n; i++){
        bool ck = 0;
        for(auto &x : v[0]){
            if(x == 1e9) {
                ck = 1;
                break;
            }
            if(!st.count(x)) {
                ans.pb(x);
                st.insert(x);
            }
            x = 1e9;
        }
        if(ck) break;

        for(int j = 1; j < n; j++){
            if(v[j][0] == 1e9) break;
            vector<int> temp;
            for(int k = 0; k < v[j].size(); k++){
                if(!st.count(v[j][k])) temp.pb(v[j][k]);
                v[j][k] = 1e9;
            }
            if(temp.size()) swap(v[j], temp);
        }

        sort(all(v));
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