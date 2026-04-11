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
    string s;
    cin >> s;

    for(int i = 1; i < n-1; i++){
        if(s[i] == '0' && s[i-1] == s[i+1] && s[i-1] == '1'){
            s[i] = '1';
        }
    }

    debug(s);

    int mx = count(all(s),'1');
    int mn = 0;

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            cnt++;
        } else {
            if(cnt > 0) {
                if(cnt >= 3){
                    mn += cnt/2 - (cnt%2 == 0);
                }
                cnt = 0;
            }
        }
        debug(cnt);
    }

    mn += cnt - cnt/3;

    cout << mn << " " << mx << nl;
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