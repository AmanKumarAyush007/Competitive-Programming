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

int n;
vector<int> v;
vector<vector<int>> tree;

int dfs(int x){
    int val = inf;

    for(auto &i : tree[x]){
        val = min(dfs(i), val);
    }

    if(x == 0) return v[x] + val;

    if(val == inf) return v[x];

    if(v[x] >= val) return min(v[x], val);
    else return (v[x] + val)/2;
}

void solve(){
    cin >> n;
    v.assign(n, 0);
    tree.assign(n, {});

    inp(v);

    tree.resize(n,{});
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        x--;
        tree[x].pb(i);
    }


    cout << dfs(0) << nl;
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