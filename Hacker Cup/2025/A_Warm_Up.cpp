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
    vector<int> a(n),b(n);
    inp(a);
    inp(b)

    map<int,int> mp;

    for(int i = 0; i < n; i++){
        if(b[i] < a[i]){
            cout << -1 << nl;
            return;
        }
        mp[a[i]] = i;
    }


    vector<pair<pair<int,int>,int>> vp(n);
    vector<pi> ans;
    for(int i = 0; i < n; i++){
        vp[i].ff.ff = a[i];
        vp[i].ff.ss = b[i];
        vp[i].ss = i;
    }

    sort(all(vp));

    for(int i = 0; i < n; i++){
        auto [a,b] = vp[i].ff;
        if(a == b) continue;
        if(mp.count(vp[i].ff.ss)){
            ans.pb({mp[vp[i].ff.ss],vp[i].ss});
        }
        else {
            cout << -1 << nl;
            return;
        }
    }
    

    if(ans.size() > n) cout << -1 << nl;
    else{
        cout << ans.size() << nl;
        for(auto &[a,b] : ans) cout << a+1 << " " << b+1 << nl;
    }

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}