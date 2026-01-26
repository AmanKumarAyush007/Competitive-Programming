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

const int mod = 1e9+7;

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    vector<int> v;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') v.pb(-1);
        else v.pb(1);
    }

    prefixsum(v);

    map<int,int> mp;
    map<int,int> sum;
    sum[0] = 1;
    mp[0] = 1;


    int ans = 0;

    for(int i = 0; i < n; i++){
        int x = v[i];
        if(mp.count(x)){
            ans = (ans + ((n-i) * sum[x])) % mod;
        }
        sum[x] = (sum[x] + (i+2)) % mod;
        mp[x]++;
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