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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    inp(a);
    inp(b);

    for(int i = 0; i < n; i++){
        if(a[i] > b[i]) {
            cout << "No\n";
            return;
        }
    }

    vector<int> pre = a;
    for(int i = 1; i < n; i++){
        pre[i] = max(pre[i], pre[i-1]);
    }

    for(int i = n-1; i >= 0; i--){
        if(b[i] > a[i]){
            if(i > 0 && (pre[i-1] >= b[i] - 1)){
                cout << "No\n";
                return;
            }
        }
    }


    cout << "Yes" << nl;
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