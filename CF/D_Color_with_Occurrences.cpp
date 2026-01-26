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
    string s;
    cin >> s;    

    int n;
    cin >> n;

    vector<string> v(n);
    inp(v);

    vector<pair<int,int>> ans;

    int curr = 0;

    while(curr < s.size()){
        array<int,3> ar{curr, -1, -1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j <= curr && j + v[i].size() <= s.size(); j++){
                if(s.substr(j, v[i].size()) == v[i]){
                    ar = max(ar, array<int,3>{(int)v[i].size() + j ,i, j});
                }
            }
        }

        if(ar[0] == curr){
            cout << -1 << nl;
            return;
        }

        curr = ar[0];
        ans.pb({ar[1],ar[2]});
    }

    cout << ans.size() << nl;
    for(auto &[a,b] : ans) cout << a+1 << " " << b+1 << nl;
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