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
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(m);
    inp(a);
    inp(b);

    int i = 0;
    int j = 0;

    int ans = 0;
    
    while(i < n && j < m){
        while(j < m && b[j] < a[i]) j++;

        if(j >= m) break;
        if(a[i] != b[j]){
            i++;
            continue;
        }

        // debug(i,j);
        
        int cnt = 1;
        while(i+1 < n && a[i+1] == a[i]) {
            cnt++;
            i++;
        }
        
        
        int x = 1;
        while(j+1 < m && b[j+1] == b[j]) {
            x++;
            j++;
        }
        // debug(i,j);

        // cerr << x << " " << cnt << nl;
        ans += x*cnt;

        i++;
        j++;

        // debug(ans);
    }

    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}