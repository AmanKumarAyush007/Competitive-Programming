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
    int n,m,k;
    cin >> n >> m >> k;
    
    vector<int> v(k);
    iota(all(v),1);

    int grid[n][m];

    if(m%k == 0){
        int st = 0;

        for(int i = 0; i < n; i++){
            int curr = st;
            for(int j = 0; j < m; j++){
                grid[i][j] = v[curr];
                curr++;
                curr %= k;
            }
            st++;
            st %= k;
        }

    }
    else if(n % k == 0){
        int st = 0;
        
        for(int i = 0; i < m; i++){
            int curr = st;
            for(int j = 0; j < n; j++){
                grid[j][i] = v[curr];
                curr++;
                curr %= k;
            }
            st++;
            st %= k;
        }
    }
    else{
        int st = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] = v[st];
                st++;
                st %= k;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j] << " ";
        }
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