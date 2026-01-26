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
    vector<int> a(n,0),b(n,0),c(n,0);
    for(int i = 0; i < n; i++){
        if(s[i] == 'a') {
            a[i]++;
        }
        if(s[i] == 'b') b[i]++;
        if(s[i] == 'c') c[i]++;
    }
    prefixsum(a);
    prefixsum(b);
    prefixsum(c);

    // debug(a,b,c);

    int ans = inf;
    int mx = min(7LL,(int)s.size());

    for(int i = 2; i <= mx; i++){
        for(int j = 0; (j+i-1) < n; j++){
            int st = j;
            int en = j+i-1;

            // debug(st,en);

            int cntb = b[en] - (st > 0 ? b[st-1] : 0);
            int cntc = c[en] - (st > 0 ? c[st-1] : 0);
            int cnta = a[en] - (st > 0 ? a[st-1] : 0);
    
            if(cnta > cntc && cnta > cntb){
                // debug(cnta,cntb,cntc);
                // debug(st,en);
                ans = min(ans,i);
            }
        }
    }

    if(ans == inf) ans = -1;


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