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
    
    vector<int> v(2*n);
    inp(v);

    int ans = 1;

    if(n == 1){
        cout << ans << nl;
        return;
    }


    int i = 0, j = (2*n)-1;

    while(i < v.size() && v[i] != 0) i++;
    while(j >= 0 && v[j] != 0) j--;

    auto pal = [&](int l, int r){
        while(l <= r && v[l] == v[r]) l++, r--;
        return (l > r);
    };

    auto mex = [&](int l, int r){
        set<int> st;
        for(int k = l; k <= r; k++){
            st.insert(v[k]);
        }
 
        int mx = 0;
 
        for(auto &i : st) {
            if(i == mx) mx++;
            else break;
        }
 
        return mx;
    };

    auto can = [&](int mid){
        int cnt = 0;
        while(mid-cnt >= 0 && mid+cnt<v.size() && v[mid-cnt] == v[mid+cnt]) {
            cnt++;
        }
        return max(0LL,cnt-1);
    };


    if(pal(i,j)) {
        int l = i, r = j;
        while(l-1 >= 0 && r+1 < v.size() && v[l-1] == v[r+1]) r++, l--;
        
        ans = max(ans, mex(l,r));
    }


    int d = can(i);
    ans = max(ans, mex(i-d, i+d));
    d = can(j);
    ans = max(ans, mex(j-d, j+d));

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