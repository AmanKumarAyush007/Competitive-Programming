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
    if(n&1) {
        if(n >= 27){
            vector<int> v(n,0);
            v[0] = 1;
            v[9] = 1;
            v[10] = 2;
            v[25] = 1;
            v[26] = 2;
            int curr = 3;
            for(int i = 0; i < n; i++){
                if(v[i] == 0){
                    v[i] = curr, v[i+1] = curr;
                    curr++;
                    i++;
                }
            }
            for(auto &i : v) cout << i << " ";
        }
        else cout << -1;
    }
    else{
        for(int i = 1; i <= n/2; i++){
            for(int j = 0; j < 2; j++){
                cout << i << " ";
            }
        }
      
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