#include<bits/stdc++.h>
using namespace std;

#define int              int64_t
#define ff               first
#define ss               second
#define pb               push_back
#define inf              LLONG_MAX
#define hell             LLONG_MIN
#define nl               endl
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

void query(int x,int k, vector<int> &v){
    cout << "? " << x << " " << k << " ";
    for(auto &i : v) cout << i << " ";
    cout << nl;
}


void solve(){
    int n;
    cin >> n;

    map<int,vector<int>,greater<int>> mp;
    vector<int> v(n);
    iota(all(v),1);


    for(int i = 1; i <= n; i++){
        query(i,n,v);
        int res;
        cin >> res;
        if (res == -1) return;
        mp[res].pb(i);
    }


    auto [x,y] = *mp.begin();

    int sz = x;

    vector<int> sol;

    sol.pb(y[0]);
    sz--;


    while(sz > 0){
        auto pos = mp[sz];

        for(auto &el : pos){
            vector<int> q;
            q.pb(sol.back());
            q.pb(el);
            query(sol.back(),2,q);

            int res;
            cin >> res;

            if(res == 2){
                sol.pb(el);
                sz--;
                break;
            }
        }
    }

    cout << "! " << sol.size() << " ";
    for(auto &i : sol) cout << i << " "; 
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