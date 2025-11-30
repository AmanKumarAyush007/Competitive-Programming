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
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; i++){
        cin >> vp[i].ff;
        vp[i].ss = i+1;
    }

    sort(all(vp));

    int i = 0, j = n-1;

    while(i < j){
        if(vp[i].ff + vp[j].ff > k){
            j--;
        }
        else if(vp[i].ff + vp[j].ff < k){
            i++;
        }
        else{
            cout << vp[i].ss << " " << vp[j].ss << nl;
            return;
        }
    }

    cout << "IMPOSSIBLE" << nl;
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