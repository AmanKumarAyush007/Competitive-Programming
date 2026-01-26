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

int grid[1005][1005];

void solve(){
    int n,q;
    cin >> n >> q;

    memset(grid, 0, sizeof(grid));

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        grid[x][y] += x*y;
    }

    for(int i = 0; i < 1005; i++){
        for(int j = 1; j < 1005; j++){
            grid[i][j] += grid[i][j-1]; 
        }
    }

    for(int j = 0; j < 1005; j++){
        for(int i = 1; i < 1005; i++){
            grid[i][j] += grid[i-1][j]; 
        }
    }

    while(q--){
        int xs,ys, xb,yb;
        cin >> xs >> ys >> xb >> yb;
        xb--, yb--;
        cout << grid[xb][yb] - grid[xs][yb] - grid[xb][ys] + grid[xs][ys] << nl;
    }

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