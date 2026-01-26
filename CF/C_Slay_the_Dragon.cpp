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
    inp(v)

    sort(all(v));
    int tot = sm(v);

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;

        auto it = lower_bound(all(v),x);

        int need;
        if(it == v.end()){
            need = x - v[n-1];
            need += max(y - (tot - v[n-1]), 0LL);
        }
        else{
            if(it == v.begin()){
                need = max(y - (tot - v[0]), 0LL);
            }
            else{
                int ind = it - v.begin();
                need = max(y - (tot - v[ind]), 0LL);
                if(v[ind] > x) need = min(need, x-v[ind-1] + max(y - (tot - v[ind-1]), 0LL));
            }
        }
        cout << need << nl;
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