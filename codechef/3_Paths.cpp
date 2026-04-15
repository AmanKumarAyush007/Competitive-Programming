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
    int n;
    cin >> n;
    if(n == 2) cout << -1 << endl;
    else if(n == 3){
        cout << "1 1 1\n";
        cout << "0 1 1\n";
        cout << "0 1 1\n";
    }
    else{
        vector<vector<int>> v(n,vector<int>(n,0));
        for(int i = 0; i < n-1; i++){
            v[0][i] = 1;
        }
        for(int i = n-3; i < n; i++){
            for(int j = n-2; j < n; j++){
                v[i][j] = 1;
            }
        }

        for(int i = 0; i < n; i++){
            v[i][n-2] = 1;
        }

        for(auto &i : v){
            for(auto &j : i) cout << j << " ";
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