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
    int n, q, k;
    cin >> n >> q >> k;

    map<int,int> mp, extra;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[i] = 0;
        v[i] = x;
        extra[i] = k - x;
    }

    vector<pair<int,int>> vp(q);

    for(int i = 0; i < q; i++){
        int ind, c;
        cin >> ind >> c;
        ind--;
        vp[i] = {ind,c};

        if(mp[ind] + c > extra[ind]){
            mp.clear();
        }
        else mp[ind] += c;
    }

    for(int i = 0; i < n; i++){
        cout << v[i] + mp[i] << " ";
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