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

vector<string> pat = {"abc","acb", "bac", "bca", "cab", "cba"};

void solve(){
    int n,m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<vector<int>> pre(6,vector<int>(n,0));

    for(int i = 0; i < 6; i++){
        if(pat[i][0] != s[0]) pre[i][0] = 1;
        for(int j = 1; j < n; j++){
            pre[i][j] = pre[i][j-1] + (pat[i][j%3] != s[j]);
        }
    }

    while(m--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = inf;

        for(int i = 0; i < 6; i++){
            ans = min(ans, pre[i][r] - (l-1 >= 0 ? pre[i][l-1] : 0));
        }

        cout << ans << nl;
    }
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