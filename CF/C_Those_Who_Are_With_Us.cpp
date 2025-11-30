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

    int a[n][m];

    map<int,int> mp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            a[i][j] = x;
            mp[x]++;
        }
    }


    auto [x,y] = *mp.rbegin();

    vector<int> r,c;

    for(int i = 0; i < n; i++){
        int tot = 0;
        for(int j = 0; j < m; j++){
            tot += (a[i][j] == x);
        }
        r.pb(tot);
    }

    for(int i = 0; i < m; i++){
        int tot = 0;
        for(int j = 0; j < n; j++){
            tot += (a[j][i] == x);
        }
        c.pb(tot);
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int tot = r[i] + c[j] - (a[i][j] == x);
            if(y == tot){
                cout << x - 1 << nl;
                return;
            }
        }
    }

    cout << x;
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