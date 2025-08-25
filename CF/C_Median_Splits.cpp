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

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    inp(a)
    
    auto find = [&](int start, int diff) {
        int cnt = 0;
        for (int i = start; i >= 0 && i < n; i += diff) {
          cnt += (a[i] <= k);
          cnt -= (a[i] > k);
          if (cnt >= 0) return i;
        }
        return diff == 1 ? n : -1;
    };
   
    auto first2 = [&]() {
        int l = find(0, 1);
        if (l % 2 == 0 && l + 1 < n && a[l + 1] > k) l++;
        int r = find(l + 1, 1);
        return r < n - 1;
    };

    auto last2 = [&]() {
        int r = find(n - 1, -1);
        if ((n - r) % 2 && r - 1 >= 0 && a[r - 1] > k) r--;
        int l = find(r - 1, -1);
        return l > 0;
    };

    auto outer2 = [&]() {
        int l = find(0, 1);
        int r = find(n - 1, -1);
        return r - l > 1;
    };

    cout << (first2() || last2() || outer2() ? "YES" : "NO") << nl;
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