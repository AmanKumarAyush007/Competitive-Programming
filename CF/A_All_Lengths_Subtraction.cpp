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
    vector<int> v(n);
    inp(v);
    int l = 0,r = 0;

    for(int i = 0; i < n; i++){
        if(v[i] == n) {
            l = i;
            r = i;
            break;
        }
    }
    // debug(l,r);
    int curr = n-1;

    while(l >= 0 && r < n){
        debug(l,r);
        if(l-1 >= 0 && v[l-1] == curr){
            // cout << "!\n";
            l--;
            curr--;
        }
        else if(r+1 < n && v[r+1] == curr){
            // cout << "!!\n";

            r++;
            curr--;
        }
        else{
            if(l == 0 && r == n-1) cout << "YES\n";
            else cout << "NO\n";
            return;
        }
    }

    cout << "YES" << nl;
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