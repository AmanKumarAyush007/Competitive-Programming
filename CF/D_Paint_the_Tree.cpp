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

vector<vector<int>> tree;
vector<int> depth;
vector<int> path;
bool found = false;

void dfs(int a, int b, int par){
    if(a == b) {
        path.pb(a);
        found = 1;
        return;
    }
    
    for(int x : tree[a]){
        if(x != par){
            dfs(x,b,a);
            if(found) {
                path.pb(a);
                return;
            }
        }
    }
}


void deep(int x, int par){
    for(int y : tree[x]){
        if(y != par){
            depth[y] = depth[x] + 1;
            deep(y,x);
        }
    }
}

void solve(){
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    a--, b--;

    tree.assign(n,{});
    depth.assign(n,0);

    
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    
    dfs(a,b, -1);

    reverse(all(path));

    int N = path.size();
    int ind = N/2;

    if(N % 2 == 0) ind--;
    int mid = path[ind];

    deep(mid,-1);

    int ans = ((N/2) + 1);

    int mx = *max_element(all(depth)) + 1;

    ans += 2*(n-1) - mx;

    cout << ans << nl;
    path.clear();
    found = 0;
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