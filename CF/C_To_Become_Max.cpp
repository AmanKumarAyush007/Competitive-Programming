#include<bits/stdc++.h>
using namespace std;

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


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    inp(v)
    
    auto check = [&](int x){
        vector<int> tr = v;
        for(int i = 0; i < n; i++){
            int curr = x;
            int cnt = 0;
            bool fnd = false;
            
            for(int j = i; j < n; j++){
                if(curr > tr[j]) cnt += curr-tr[j] ;
                else {
                    fnd = true;
                    break;
                }
                curr--;

            }
            if(fnd && (k >= cnt)) {
                debug(i, cnt, curr);
                return true;
            }
        }

        return false;
    };
    
    int hi = 1e9, lo = 0;
    int ans = 0;
    
    while(lo <= hi){
        int mid = (lo + hi)/2;

        if(check(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    
    cout << ans;
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