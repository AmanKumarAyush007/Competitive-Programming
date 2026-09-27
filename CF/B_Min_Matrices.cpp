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
    int n,k;
    cin >> n >> k;

    if(k < n || k == 2*n) cout << -1 << nl;
    else {
        vector<vector<int>> mat(n, vector<int>(n,-1));

        int x = 1;

        for(auto &row : mat) row[0] = x++;

        for(int i = 1; i < n; i++){
            if(x > k) break;
            mat[0][i] = x++;
        }

        for(int j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                if(mat[i][j] == -1) mat[i][j] = x++;
            }
        }
        
        for(int j = 0; j < n; j++){
            int mn = 1e9;
            for(int i = 0; i < n; i++){
                mn = min(mn, mat[i][j]);
            }
            // debug(mn);
            if(mn > k) swap(mat[j][0], mat[j][j]);
        }
        

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << mat[i][j] << " ";
            }
            cout << nl;
        }
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