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
    int n,m;
    cin >> n >> m;
    int grid[n][m];

    int tot = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            tot += grid[i][j];
        }
    }

    int suff[n][m];
    for(int j = 0; j < m; j++){
        suff[n-1][j] = grid[n-1][j];
        for(int i = n-2; i >= 0; i--){
            suff[i][j] = suff[i+1][j] + grid[i][j];
        }
    }


    int req = tot/2;

    cout << req * (tot-req) << nl;

    int r = 0; int c = 0;

    while(r < n && c < m){
        while(c < m && suff[r][c] <= req){
            req -= suff[r][c];
            cout << 'R';
            c++;
        }
        while(r < n && suff[r][c] > req) {
            cout << "D";
            r++;
        }
    }

    while(r<n) {
        cout << 'D';
        r++;
    }

    while(c < m){
        cout << 'R';
        c++;
    }

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