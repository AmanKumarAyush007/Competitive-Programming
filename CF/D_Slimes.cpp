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

    vector<int> nxt(n, n);
    for(int i = n-2; i >= 0; i--){
        if(v[i] == v[i+1]) nxt[i] = nxt[i+1];
        else nxt[i] = i+1;
    }

    vector<int> pre = v;
    prefixsum(pre);
    
    auto compute = [&](int l, int r){
        int ans = inf;

        if(nxt[l] > r && r-l+1 != 1){
            return v[l];
        }

        ans = pre[r] - (l-1 >= 0 ? pre[l-1] : 0);
        return ans;
    };

    auto check = [&](int len, int ind){
        int l = ind > 0 ? compute(max(0LL, ind - len), max(0LL, ind-1)) : inf;
        int r = ind < n-1 ? compute(min(n-1, ind+1), min(n-1, ind+len)) : inf;

        if(l == inf && r == inf) return false;
        else if(l == inf) return v[ind] < r;
        else if(r == inf) return v[ind] < l;
        else return (v[ind] < max(l,r));
    };

    for(int i = 0; i < n; i++){
        int lo = 1, hi = n;
        int ans = -1;

        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(check(mid, i)){
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << " ";
    }

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