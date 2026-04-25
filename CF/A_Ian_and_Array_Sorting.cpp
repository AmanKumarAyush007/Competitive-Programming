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

    vector<int> v(n);
    inp(v);

    for(int i = 1; i < n-1; i++){
        if(v[i] < v[i-1]){
            int diff = v[i-1] - v[i];
            v[i+1] += diff; 
            v[i] += diff; 
        }
    }


    for(int i = n-2; i >= 1; i--){
        if(v[i+1] < v[i]){
            int diff = v[i] - v[i+1];
            v[i-1] -= diff;
            v[i] -= diff; 
        }
    }
    

    for(int i = 0; i < n-1; i++){
        if(v[i] > v[i+1]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES" << nl;
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