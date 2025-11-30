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
    int n,x;
    cin >> n >> x;

    vector<int> ans(n+1);
    ans[1] = x, ans[n] = 1;

    if(n % x != 0){
        cout << -1 << nl;
        return;
    }
    else{
        for(int i = 2; i < n; i++){
            if(i == x) ans[i] = n;
            else ans[i] = i;
        }

        for(int i = x+1; i < n; i++){
            if(n % i == 0 && ans[i] % x == 0){
                swap(ans[x],ans[i]);
                x = i;
            }
        }
    }


    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
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