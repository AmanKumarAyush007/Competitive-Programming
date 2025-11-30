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

    sort(all(v));

    vector<int> ans;

    for(int i = 0; i < n/2; i++){
        ans.pb(v[i]);
        if(i + n/2 < n)ans.pb(v[i + n/2]);
    }

    if(n&1)ans.pb(v[n-1]);

    for(int i = 0; i < n; i++){
        int l = (i-1 + n)%n;
        int r = (i+1) % n;

        if((ans[i] > ans[l] && ans[i] > ans[r]) || (ans[i] < ans[l] && ans[i] < ans[r])) continue;
        else {
            cout << "NO\n";
            return;
        }
    }

    cout <<"YES\n";
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