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

    int grid[n][m];
    vector<int> row((n*m)+5), col((n*m)+5);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            row[grid[i][j]] = i;
            col[grid[i][j]] = j;
        }
    }


    map<int,int> newr, newc;

    bool ok = true;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            int oldr = row[x];
            int oldc = col[x];
            if(newr.count(oldr) && newr[oldr] != i){
                ok = false;
            }
            if(newc.count(oldc) && newc[oldc] != j){
                ok = false;
            }

            if(!ok) continue;

            newr[oldr] = i;
            newc[oldc] = j;
        }
    }

    if(ok) cout << "YES" << nl;
    else cout << "NO" << nl;
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