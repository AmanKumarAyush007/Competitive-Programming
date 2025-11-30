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

    vector<vector<int>> v(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    set<pair<int,int>>st;

    int l = -1;
    int r = -1;
    for(int i = 0; i < n; i++){
        auto x = v[i];
        sort(all(x));
        int cnt = 0;


        if(l == -1 || r == -1){
            for(int j = 0; j < m; j++){
                if(x[j] != v[i][j]) {
                    cnt++;
                    if(cnt > 2){
                        cout << -1 << nl;
                        return;
                    }
                    if(cnt == 1) l = j;
                    if(cnt == 2) r = j;
                }
            }

        }
        if(l != -1 && r != -1) {
            // swap(v[i][l],v[i][r]);
            break;
        }
    }

    

    if(l == -1 && r == -1) l = r = 0;

    for(int i = 0; i < n; i++){
        swap(v[i][l],v[i][r]);
        if(!is_sorted(all(v[i]))){
            cout << -1 << nl;
            return;
        }
    }

    cout << l+1 << " " << r+1;
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