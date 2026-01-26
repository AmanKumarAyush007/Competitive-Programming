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

    vector<int> pre = v;
    vector<int> suff = v;
    pre[0] = v[0];
    suff[n-1] = v[n-1];

    int ans = 0;

    for(int i = 1; i < n; i++){
        pre[i] ^= pre[i-1];
        if(pre[i] == 0) ans = i+1;
    }

    for(int i = n-2; i >= 0; i--){
        suff[i] ^= suff[i+1];
        if(suff[i] == 0) ans = max(ans,n-i);
    }

    map<int,int> mp, ms;

    for(int i = 0; i < n; i++){
        if(!mp.count(pre[i])) mp[pre[i]] = i;
    }

    for(int i = n-1; i >= 0; i--){
        if(!ms.count(suff[i])) ms[suff[i]] = i;
    }

    for(int i = 0; i < n; i++){
        int fst = mp[pre[i]];
        ans = max(ans, i - fst);
    }

    for(auto &[x,y] : mp){
        if(ms.count(x)){
            int lst = y;
            int fst = ms[x];
            if(fst > lst){
                int tot = n-fst + lst + 1;
                ans = max(ans,tot);
            }
        }
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