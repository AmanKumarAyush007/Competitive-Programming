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
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> ans(n, -1);

    for(int i = 0; i < n; i++){
        int curr = r - (r%(n-i));
        if(curr < l) {
            cout << "NO\n";
            return;
        }

        while(curr >= l){
            if(gcd(curr,n-i) == n-i){
                ans[n - i - 1] = curr; 
                break;
            }
            curr -= n-i;
        }

        if(ans[n-i-1] == -1) {
            cout << "NO\n";
            return;
        }
    }

    for(int i = 0; i < n; i++){
        assert(gcd(ans[i] , (i+1)) == i+1);
    }

    for(auto &i : ans){
        if(i == -1) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for(auto &i : ans) cout << i << " ";
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