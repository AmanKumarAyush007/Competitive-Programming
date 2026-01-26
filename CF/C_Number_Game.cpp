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

    auto check = [&](int mid){
        multiset<int> ms(all(v));
        int curr = mid;
        for(int i = 1; i <= mid; i++){
            auto it = ms.upper_bound(curr);
            if(it == ms.begin()) return false;
            it = prev(it);
            ms.erase(it);
            if(ms.size()){
                int x = *ms.begin();
                ms.erase(ms.begin());
                ms.insert(x+curr);
            }
            curr--;
        }
        return true;
    };

    int hi = 1e18, lo = 0;
    int ans = 0;
    while(hi >= lo){
        int mid = (hi + lo)/2;
        if(check(mid)){
            lo = mid+1;
            ans = mid;
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