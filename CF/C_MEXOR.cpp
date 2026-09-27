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
#define lg(x)            (63LL - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());


int msb(int x){
    for(int i = 63; i >= 0; i--){
        if((1LL << i) & x) return i;
    }
    return -1;
}


void solve(){
    int n,k;
    cin >> n >> k;


    if(msb(k^n) > msb(n-1)){
        cout << "NO\n";
        return;
    }

    vector<int> ans;

    vector<int> v(n);
    iota(all(v),0);
    
    
    set<int> st(all(v));
    

    if((k^n) <= n-1){
        for(int i = 0; i < n; i++){
            if(i == 0 || i == (k^n)) continue;
            ans.pb(i);
            st.erase(i);
        }
        for(auto &i : st) ans.pb(i);
    }
    else {
        int x = 1LL << msb(k^n);
        int y = (k^n) ^ x;

        for(int i = 0; i < n; i++){
            if(i == 0 || i == x || i == y) continue;
            ans.pb(i);
            st.erase(i);
        }

        for(auto &i : st) ans.pb(i);
    }

    cout << "YES\n";
    for(auto &i : ans) cout << i << " ";
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