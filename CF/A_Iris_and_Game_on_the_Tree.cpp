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

    vector<vector<int>> tree(n);
    int c0 = 0, c1 = 0, c2 = 0;

    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        tree[x].pb(y);
        tree[y].pb(x);
    }

    string s;
    cin >> s;

    for(int i = 1; i < n; i++){
        if(tree[i].size() == 1){
            if(s[i] == '?') c2++;
            else if(s[i] == '1') c1++;
            else c0++;
        }
    }

    int cnt = count(all(s), '?') - c2 - (s[0] == '?');

    int ans = 0;

    if(s[0] == '?'){
        ans = max(c1,c0);
        ans += (c2 + ((c1 == c0) && cnt%2)) / 2;
    }
    else {
        ans = (s[0] == '0' ? c1 : c0);
        ans += (c2+1)/2;
    }

    cout << ans << nl;
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