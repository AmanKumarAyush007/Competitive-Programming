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

    map<int,int> mp;
    for(auto &i : v) mp[i]++;

    int q;
    cin >> q;

    while(q--){
        int x,y;
        cin >> x >> y;
        if(x*x < 4*y) cout << 0 << " ";
        else{
            int ans = 0;
            int d = (x*x) - (4*y);
            int und = sqrt(d);
            if(und*und != d) cout << ans << " ";
            else{
                int r1 = (x + und)/2;
                int r2 = x - r1;

                if(r1 == r2) ans += (mp[r1]*(mp[r1]-1))/2;
                else ans += mp[r1]*mp[r2];

                cout << ans << " ";
            }
        }
    }
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