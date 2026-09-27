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

int dig(int x){
    int res = 0;
    while(x > 0){
        res += (x % 10) * (x % 10);
        x = x/10;
    }
    return res;
}


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    int ans = 0, cnt = 0;


    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            
            int x = v[i];
            int y = v[j];

            for(int k = 0; k < 100; k++){
                if(x == y){
                    ans++;
                    break;
                }
                x = dig(x), y = dig(y);
            }
            
        }
    }

    cout << ans << nl;
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