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
    int n, k;
    cin >> n >> k;

    if(k + 1 == n*n) cout << "NO\n";
    else{
        cout << "YES\n";
        
        vector<vector<char>> grid(n,vector<char>(n,'D'));

        k = n*n - k;

        if(k == 0){
            for(auto &i : grid) {
                for(auto &j : i) cout << j;
                cout << nl;
            }
            return;
        }
        debug(k);

        if(k < n){
            grid[0][k-1] = 'L';
            for(int i = 0; i < k-1; i++){
                grid[0][i] = 'R';
            }
        }
        else{
            grid[0][0] = 'R';

            for(int i = 1; i < n; i++){
                grid[0][i] = 'L';
            }

            k -= n;
            
            for(int i = 1; i < n; i++){
                if(k == 0) break;
                for(int j = 0; j < n; j++){
                    if(k == 0) break;
                    k--;
                    grid[i][j] = 'U';
                }
            }
        }

        for(auto &i : grid) {
            for(auto &j : i) cout << j;
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