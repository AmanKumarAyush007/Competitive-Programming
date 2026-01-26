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

    auto check = [&](int mid){
        int ind = lower_bound(all(v),mid) - v.begin();

        set<int> st;

        for(int i = 0; i < ind; i++){
            st.insert(v[i]%mid);
        }

        // cout << ind;

        if(st.size() > 1) return false;
        if(st.size() == 0) return true;

        int r = *st.begin();

        // cout << r;

        for(int i = ind; i < n; i++){
            if(v[i] - r < mid) return false;
        }

        return true;
    };

    // cout << check(6);
    // return;

    int hi = 1e9+5, lo = 0;
    int ans = 0;

    while(hi >= lo){
        int mid = (lo+hi)/2;

        if(check(mid)){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid - 1;
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