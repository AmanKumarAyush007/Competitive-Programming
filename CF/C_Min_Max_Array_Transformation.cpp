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
    vector<int> a(n), b(n);
    inp(a);
    inp(b);

    int j = 0;
    for(int i = 0; i < n; i++){
        while(b[j] < a[i]) j++;
        cout << b[j] - a[i] << " ";
    }
    cout << nl;

    vector<int> maxx(n);

    maxx[n-1] = b[n-1] - a[n-1];

    j = n-1;

    for(int i = n-2; i >= 0; i--){
        if(a[i+1] > b[i]){
            j = i;
        }
        maxx[i] = b[j] - a[i];
    }


    for(auto &i : maxx) cout << i << " ";
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