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

    vector<int> a(n+1), b(n+1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }

    auto bt = [&](int x){
        int cnt = 0;
        
        for(int i = 1; i <= n; i++){
            if((1LL << x) & a[i]) cnt++;
            if((1LL << x) & b[i]) cnt++;
        }
        
        return ((cnt%2) == 1);
    };
    
    for(int i = 32; i >= 0; i--){
        if(bt(i)){
            for(int j = n; j > 0; j--){
                if(((1LL << i) & (a[j])) != ((1LL << i) & (b[j]))){
                    if(j&1) cout << "Ajisai\n";
                    else cout << "Mai\n";
                    return;
                }
            }
        }
    }
    cout << "Tie" << nl;
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