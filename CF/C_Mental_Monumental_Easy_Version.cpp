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

vector<int> pre(1e6+5, 0);

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    inp(v);

    map<int,int> mp;

    
    for(int i = 0; i <= n; i++){
        pre[i] = 0;
    }
    
    
    for(auto &i : v){
        mp[i]++;
        if(i == 0) {
            continue;
        }
        int ind = (i-1)/2;
        pre[ind+1]--;
    }
    
    pre[0] = n - mp[0];

    for(int i = 1; i <= n; i++){
        pre[i] += pre[i-1];
    }

    // for(int i = 0; i <= n; i++){
    //     cout << pre[i] << " ";
    // }
    // cout << endl;


    int ans = 0;

    for(int i = 0; i <= n; i++){
        // debug(pre[i]);
        if(i == 0 && mp[i]){
            ans = i;
            continue;
        }
        if(pre[i] == 0){
            if(mp[i] == 0) break;
            else {
                ans = i+1;
                mp[i]--;
            }
        } 
        else ans = i;
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