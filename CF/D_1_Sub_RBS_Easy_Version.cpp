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
    string s;
    cin >> s;

    vector<int> pre(n), suff(n);
    pre[0] = 1;
    suff[n-1] = 1;

    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + (s[i] == '(');
    }

    for(int i = n-2; i >= 0; i--){
        suff[i] = suff[i+1] + (s[i] == ')');
    }

    int ind = -1;

    for(int i = 0; i < n; i++){
        if(s[i] == ')'){
            ind = i+1;
            break;
        }
    }

    int ans = -1;

    for(int i = 0; i < n-1; i++){
        int l = pre[i];
        int r = suff[i+1];
        int mn = min(l,r);
        if(mn >= ind) ans = max(ans,2*mn);
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