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

using pi = pair<int,int>;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int m;
    cin >> m;
    
    vector<int> x(n,0), y(n,0);
    
    for (int i = 0; i < n; i++) {
        if(s[i] == 'R') x[i]++;
        else if(s[i] == 'L') x[i]--;
        else if(s[i] == 'U') y[i]++;
        else y[i]--;
    }
    
    vector<int> xpre = x, ypre = y;
    
    partial_sum(xpre.begin(),xpre.end(),xpre.begin());
    partial_sum(ypre.begin(),ypre.end(), ypre.begin());
    
    map<pi,pi> mp, ans;
    
    vector<pi> v(m);
    
    for (int i = 0; i < m; i++){
        int p,q;
        cin >> p >> q;
        mp[{-p,-q}] = {p,q};
        v[i] = {p,q};
    }


    for (int i = n-1; i >= 0; i--) {
        
        int a = xpre[i];
        int b = ypre[i];
        
        if(ans.count({a + x[i],b + y[i]})) {
            ans[{a,b}] = ans[{a + x[i],b + y[i]}];
        }
        else ans[{a,b}] = {xpre[n-1] - a - x[i], ypre[n-1] - (b + y[i])};
    }
    
    
    for (int i = 0; i < m; i++){
        auto [p,q] = v[i];
        if(ans.count({-p,-q})) cout << ans[{-p,-q}].ff << " " << ans[{-p,-q}].ss << nl;
        else cout << p + xpre[n-1] << " " << q + ypre[n-1] << nl;
    }
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