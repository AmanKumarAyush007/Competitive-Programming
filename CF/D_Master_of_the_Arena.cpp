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

using pi = pair<int,int>;

void solve(){
    int n;
    cin >> n;

    char grid[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    vector<pi> ans;

    for(int j = 1; j < n; j++){
        if(grid[0][j] != '0') {
            if(grid[0][j] == '?'){
               grid[0][j] = '1';
               grid[j][0] = '0';
            }
            ans.pb({0,j});
        }
        else{
            bool ck = true;
            for(int i = 0; i < n; i++){
                if(grid[j][i] != '1') {
                    if(grid[j][i] == '?'){
                        grid[j][i] = '0';
                        grid[i][j] = '1';
                    }
                    ans.pb({i,j});
                    ck = 0;
                    break;
                }
            }
            if(ck) {
                cout << "No\n";
                cout << nl;
                return;
            }
        }
    }


    cout << "Yes\n";
    for(auto &[a,b] : ans) cout << a+1 << " " << b+1 << nl;
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