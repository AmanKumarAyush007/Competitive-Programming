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



    vector<int> v(n);

    for(int i = 0; i < n; i++){
        v[i] = s[i] - '0';
    }

    debug(v);

    prefixsum(v);

    reverse(all(v));

    debug(v);


    vector<int> ans;

    int ex = 0;
    int pt = 1;
    for(auto &i : v) {
        i += ex;
        if(pt != n)ans.pb(i%10);
        else ans.pb(i);
        ex = i/10;
        pt++;
    }

    while(ans.back() == 0) ans.pop_back();

    reverse(all(ans));

    for(auto &i : ans) cout << i;
    cout << nl;
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