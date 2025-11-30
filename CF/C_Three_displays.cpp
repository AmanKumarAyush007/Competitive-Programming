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
    vector<int> s(n),c(n);
    inp(s);
    inp(c);

    int ans = inf;

    for(int i = 0; i < n; i++){
        int curr = c[i];
        int mn = inf;

        for(int j = 0; j < i; j++){
            if(s[i] > s[j]) mn = min(mn,c[j]);
        }
        if(mn == inf) continue;
        else{
            curr += mn;
            mn = inf;
            for(int j = i+1; j < n; j++){
                if(s[i] < s[j]) mn = min(mn,c[j]);
            }
            if(mn == inf) continue;
            else curr += mn;
        }

        ans = min(curr,ans);
    }

    if(ans == inf) ans = -1;

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