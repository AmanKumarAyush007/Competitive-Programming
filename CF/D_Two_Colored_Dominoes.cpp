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
    int n,m;
    cin >> n >> m;

    char grid[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vector<int> row(n,0), col(m,0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'U') row[i]++;
        }
        if(row[i]&1){
            cout << -1 << nl;
            return;
        }
    }

    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(grid[i][j] == 'L') col[j]++;
        }
        if(col[j]&1){
            cout << -1 << nl;
            return;
        }
    }


    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'U') {
                char chu = 'W';
                char chd = 'B';
                if(cnt >= row[i]/2) swap(chu,chd);
                grid[i][j] = chu;
                grid[i+1][j] = chd;
                cnt++;
            }
        }
    }

    for(int j = 0; j < m; j++){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(grid[i][j] == 'L'){
                char chl = 'W';
                char chr = 'B';
                if(cnt >= col[j]/2) swap(chl,chr);
                grid[i][j] = chl;
                grid[i][j+1] = chr;
                cnt++;
            }
        }
    }


    for(auto &i : grid){
        for(auto &j : i) cout << j;
        cout << nl;
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