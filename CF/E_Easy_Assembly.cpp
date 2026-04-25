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
    int n;
    cin >> n;

    vector<int> v;

    vector<vector<int>> vv;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        vector<int> temp;

        while(x--){
            int y;
            cin >> y;
            v.pb(y);
            temp.pb(y);
        }

        vv.pb(temp);
    }

    sort(all(v));

    map<int,int> mp;
    for(int i = 0; i < v.size(); i++){
        mp[v[i]] = i;
    }


    int cut = 0;
    int join = 0;

    for(auto &i : vv){
        int cnt = 0;
        for(int j = 0; j < i.size()-1; j++){
            if(mp[i[j]]+1 != mp[i[j+1]]) cnt++;
        }

        cut += cnt;
        join += cnt+1;
    }


    cout << cut << " " << join-1 << nl;
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