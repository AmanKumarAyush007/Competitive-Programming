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
    int n,m;
    cin >> n >> m;
    int nobel = n;

    vector<int> friends(n,0);

    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        if(u > v) swap(u,v);
        friends[u]++;
    }

    for(auto &i : friends) if(i) nobel--;


    int q;
    cin >> q;

    while(q--){
        int qt;
        cin >> qt;

        if(qt == 3){
            cout << nobel << nl;
        }
        else{
            int u,v;
            cin >> u >> v;
            u--, v--;

            if(u > v) swap(u,v);
            if(qt == 1){
                if(friends[u] == 0) nobel--;
                friends[u]++;
            }
            else{
                friends[u]--;
                if(friends[u] == 0) nobel++;
            }
        }
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