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
    int a,b;
    cin >> a >> b;
    if(lg(a) < lg(b)) cout << -1 << nl;
    else{
        vector<int> ans;
        for(int i = 31; i >= 0; i--){
            if(b & (1LL << i)){
                if((a & (1LL << i)) == 0) {
                    a |= (1LL << i);
                    ans.pb(1LL << i);
                }
            }
        }

        for(int i = 0; i < 32; i++){
            if(a & (1LL << i)){
                if((b & (1LL << i)) == 0) {
                    a ^= (1LL << i);
                    ans.pb(1LL << i);
                }
            }
        }

        if(a != b){
            cout << -1 << nl;
            return;
        }

        cout << ans.size() << nl;
        for(auto &i : ans) cout << i << " ";
        if(ans.size()) cout << nl;
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