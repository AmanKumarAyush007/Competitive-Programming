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
    int n,q;
    cin >> n >> q;
    string s,t;
    cin >> s >> t;
    vector<int> a(n),b(n),c(n), d(n);

    for(int i = 0; i < n; i++){
        if(s[i] == t[i]){
            if(s[i] == '0') a[i]++;
            else b[i]++;
        }
        else{
            if(s[i] == '0') c[i]++;
            else d[i]++;    
        }
    }

    prefixsum(a);
    prefixsum(b);
    prefixsum(c);
    prefixsum(d);

    
    while(q--){
        int l,r;
        cin >> l >> r;
        l--, r--;

        auto calc = [&](vector<int> &v){
            return v[r] - (l > 0 ? v[l-1] : 0);
        };

        
        if(abs(calc(c) - calc(d)) == 0) cout << "YES\n";
        else if(abs(calc(c) - calc(d)) <= calc(a) + calc(b)) cout << "YES\n";
        else cout << "NO\n";
    }
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