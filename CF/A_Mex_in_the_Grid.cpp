#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)
#define lg(x)      (63 - __builtin_clzll(x)) //log base 2


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif



void solve(){
    int n;
    cin >> n;
    if(n == 1) cout << 0 << nl;
    else{
        vector<vector<int>> v(n,vector<int>(n));
        int st = (n*n) - 1;
        for(int i = 0; i < n-2; i++){
            v[i][i] = st;
            st--;
            for(int j = n-1; j > i; j--){
                v[j][i] = st;
                st--;
            }
            for(int j = n-1; j > i; j--){
                v[i][j] = st;
                st--;
            }
            
        }

        v[n-1][n-1] = 3;
        v[n-2][n-1] = 1;
        v[n-1][n-2] = 2;
        v[n-2][n-2] = 0;

        for(auto &i : v){
            for(auto &el : i) cout << el << " ";
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