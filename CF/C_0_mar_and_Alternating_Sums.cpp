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

const int mod = 1e9+7;

int binpow(int b, int a = 2){
    if(b <= 0) return 1;
    int t = binpow(b/2, a) % mod;
    int ret = (t*t) % mod;
    if(b&1) ret *= a;
    ret %= mod;
    return ret;
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    map<int,int> mp;
    for(auto &i : v) mp[i]++;


    int ans = 1;
    vector<pair<int,int>> fre;
    vector<int> pre, suff;

    for(auto &[a,b] : mp){
        int x = binpow(b-1);
        fre.pb({a,x});
        pre.pb(x);
        suff.pb(x);
        ans = (ans * x) % mod;
    }


    int cnt = 0;
    for(int i = 1; i < fre.size()-1; i++){
        auto [x,y] = fre[i];
        auto [a,b] = fre[i+1];
        if(a-x != 1) continue;
        cnt++;
    }


    if(mp[-1]) ans = (ans + (ans*(cnt))%mod)%mod;
    
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