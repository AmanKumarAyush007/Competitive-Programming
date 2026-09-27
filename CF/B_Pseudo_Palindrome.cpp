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
    int n,d;
    cin >> n >> d;
    vector<int> v(n);
    inp(v);

    if(n == 1){
        cout << "YES\n";
        return;
    }

    multiset<int> ms(all(v));

    int ans = 0;

    while(ms.size() > 1){
        auto it = ms.begin();
        auto nxt = next(it);
        
        auto lst = prev(ms.end());
        auto scn = prev(lst);

        if(abs(*it - *nxt) <= abs(*lst - *scn)){
            ans = max(ans, abs(*it - *nxt));
            ms.erase(it);
            ms.erase(nxt);
        }
        else{
            ans = max(ans, abs(*lst - *scn));
            ms.erase(lst);
            ms.erase(scn);
        }
    }

    cout << (d >= ans ? "YES" : "NO");
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