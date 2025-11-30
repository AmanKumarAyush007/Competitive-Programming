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
    int q;
    cin >> q;
    vector<int> v(n);
    inp(v)

    vector<int> ind;
    for(int i = 0; i < n-1; i++){
        if(v[i] == v[i+1]) ind.pb(i);
    }


    prefixsum(v);

    while(q--){
        int l,r;
        cin >> l >> r;
        l--, r--;

        int tot = (r-l+1);
        int cnt = ((v[r] - (l > 0 ? v[l-1] : 0)));


        if((tot%3 != 0) || (cnt%3 != 0)) cout << -1;
        else{
            auto it = lower_bound(all(ind), l);

            int ans = tot/3 + (!(it != ind.end() && *it < r));
           
            cout << ans;
        }
        cout << nl;
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