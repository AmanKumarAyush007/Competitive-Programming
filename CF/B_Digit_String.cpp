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

    vector<int> pre(n), suff(n);
    pre[0] = (s[0] == '1' || s[0] == '3');
    suff[n-1] = s[n-1] == '2';

    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + (s[i] == '1' || s[i] == '3');
    }

    for(int i = n-2; i >= 0; i--){
        suff[i] = suff[i+1] + (s[i] == '2');
    }

    int mn = min(pre[n-1], suff[0]);
    for(int i = 0; i < n-1; i++){
        mn = min(mn,pre[i]+suff[i+1]);
    }

    cout << count(all(s),'4') + mn << nl;
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