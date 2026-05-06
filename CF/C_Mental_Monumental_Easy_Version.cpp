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

    vector<int> v(n);
    inp(v);

    sort(all(v));

    auto check = [&](int x){
        multiset<int> ms(all(v));

        for(int i = x; i >= 0; i--){
            if(ms.count(i)) ms.erase(ms.find(i));
            else{
                auto it = ms.lower_bound(2*i+1);
                if(it == ms.end()) return false;
                else ms.erase(it);
            }
        }  

        return true;
    };

    
    int hi = n+10, lo = 0;
    int ans = 0;

    while(hi >= lo){
        int mid = (hi+lo)/2;

        if(check(mid)){
            ans = mid + 1;
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