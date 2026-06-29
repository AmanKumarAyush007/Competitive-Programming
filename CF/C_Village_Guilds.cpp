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

int ans;
vector<vector<int>> tree;

int dfs(int x, int d = 1){
    ans++;

    vector<int> temp;
    for(auto &child : tree[x]){
        temp.pb(dfs(child,0)+1);
    }

    sort(all(temp));

    if(temp.size() > 1) ans += temp[temp.size() - 2];

    if(temp.size() == 0) return d;
    return temp.back();
}
void solve(){
    int n;
    cin >> n;

    ans = 0;
    tree.assign(n,{});

    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        x--;
        tree[x].pb(i);
    }


    dfs(0);

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