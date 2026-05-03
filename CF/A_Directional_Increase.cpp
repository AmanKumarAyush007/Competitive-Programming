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

    vector<int> b(n);
    b[0] = v[0];

    
    if(b[0] < 0){
        cout << "No\n";
        return;
    }
    

    for(int i = 1; i < n; i++){
        b[i] = v[i] + b[i-1];
    }

    for(int i = 0; i < n; i++){
        if(b[i] < 0){
            cout << "No\n";
            return;
        }
    }

    bool ck = 0;

    for(int i = 0; i < n; i++){
        if(b[i] == 0) ck = 1;
        else if(ck == 1 || (i == n-1 && b[i] != 0)){
            cout << "No\n";
            return;
        }   
    }

    cout << "Yes\n";
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