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

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    struct sol
    {
        int i,j,x,y;
    };
    

    vector<sol> ans;

    
    for(int i = 0; i < n-1; i += 2){
        int mn = min(v[i],v[i+1]);
        v[i] = mn;
        v[i+1] = mod;
        sol temp;
        temp.i = i;
        temp.x = mn;
        temp.j = i+1;
        temp.y = mod;
        ans.pb(temp);
    }


    cout << ans.size() << nl;
    for(auto &[a,b,c,d] : ans) cout << a+1 << " " << b+1 << " " << c << " " << d << nl;

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