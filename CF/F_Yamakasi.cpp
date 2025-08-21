#include<bits/stdc++.h>
using namespace std;

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


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n,s,x;
    cin >> n >> s >> x;
    vector<int> v(n);
    inp(v)

    auto cnt = [&](int xd){
        int ans = 0, pre = 0;
        map<int,int> mp;

        mp[0] = 1;

        for(int i = 0; i < n; i++){
            if(v[i] > xd){
                mp.clear();
                mp[0] = 1;
                pre = 0;
                continue;
            }

            pre += v[i];

            if(mp.count(pre - s)) ans += mp[pre-s];

            mp[pre]++;
        }

        return ans;
    };
    
    cout << cnt(x) - cnt(x-1) << nl;
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