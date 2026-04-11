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
    string s;
    cin >> s;
    int n = s.size();

    if(n == 1) {
        cout << 0 << nl;
        return;
    }

    int ans = 0;

    vector<int> v;
    for(int i = 1; i < n; i++){
        v.pb(s[i] - '0');
    }
    sort(rall(v));

    int tot = sm(v) + (s[0] - '0');

    int i = 0;
    int fst = s[0] - '0';


    while(i < v.size() && v[i] > fst-1){
        if(tot <= 9) break;
        tot -= v[i];
        i++;
        ans++;
    }

    if(fst > 1 && tot > 9) {
        tot -= fst-1;
        ans++;
    }
    
    while(i < v.size() && tot > 9){
        tot -= v[i];
        i++;
        ans++;
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