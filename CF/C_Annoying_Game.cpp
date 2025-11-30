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
    int n,k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    inp(a);
    inp(b);

    vector<int> pre(n),post(n);
    pre[0] = a[0];
    post[n-1] = a[n-1];

    
    for(int i = 1; i < n; i++){
        pre[i] = a[i] +  max(0LL,pre[i-1]); 
    }
    
    for(int i = n-2; i >= 0; i--){
        post[i] = a[i] +  max(0LL,post[i+1]); 
    }
    
    if(k&1){
        int ans = hell;
        for(int i = 0; i < n; i++){
            ans = max(ans,pre[i] + post[i] - a[i] + abs(b[i]));
        }
        cout << ans << nl;
    }
    else {
        cout << *max_element(all(pre)) << nl;
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