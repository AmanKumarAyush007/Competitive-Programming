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
    int n;
    cin >> n;

    vector<pair<int,int>> vp(n-1);
    map<int,int> deg;

    for(int i = 0; i < n-1; i++){
        int x,y;
        cin >> x >> y;
        vp[i].ff = x;
        vp[i].ss = y;
        deg[x]++;
        deg[y]++;
    }

    int ans = 0;

    for(auto &[a,b] : vp) ans = max(ans,deg[a] + deg[b] - 2);

    vector<pair<int,int>> non;

    for(auto &[x,y] : deg) non.pb({y,x});

    sort(all(non));

    reverse(all(non));

    map<pair<int,int>,int> valid;

    for(auto &[a,b] : vp){
        valid[{a,b}]++;
    }


    for(int i = 0; i < non.size(); i++){
        auto [degree,ver] = non[i];

        for(int j = i+1; j < non.size(); j++){
            if(valid.count({ver,non[j].ss}) || valid.count({non[j].ss,ver})) continue;
            else{
                ans = max(ans,degree + non[j].ff - 1);
                break;
            }
        }
    }

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