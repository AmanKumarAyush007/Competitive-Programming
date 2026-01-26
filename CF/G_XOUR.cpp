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

    map<int,set<int>> mp;

    for(int i = 0; i < n; i++){
        mp[v[i]].insert(i);
    }

    for(int i = 0; i < n; i++){
        vector<int> temp;
        temp.pb(v[i]^1);
        temp.pb(v[i]^2);
        temp.pb(v[i]^3);

        sort(all(temp));


        for(auto &val : temp){
            if(val >= v[i]) break;
            auto it = mp[val].upper_bound((i));
            if(it != mp[val].end()){
                int ind = *it;
                mp[val].erase(it);
                mp[val].insert(i);
                mp[v[i]].erase(i);
                mp[v[i]].insert(ind);
                swap(v[i],v[ind]);
                break;
            }
        }
    }

    for(auto &i : v) cout << i << " ";
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