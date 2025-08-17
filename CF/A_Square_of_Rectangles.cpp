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
    int l1, b1, l2, b2, l3, b3;
    cin>>l1>>b1>>l2>>b2>>l3>>b3;

    if(l1+l2+l3 == b1 && b1==b2 && b2==b3) cout<<"YES\n";
    else if(l2+l3 == l1 && b2==b3 && b1+b2==l1) cout<<"YES\n";
    else if(b1+b2+b3 == l1 && l1==l2 && l2==l3) cout<<"YES\n";
    else if(b2+b3 == b1 && l2==l3 && l1+l2==b1) cout<<"YES\n";
    else cout<<"NO\n";
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