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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    inp(a);
    inp(b);


    set<int> st(all(b));
    vector<int> req;

    for(auto &i : a) if(!st.count(i)) {
        req.pb(i);
    }

    int p = 0;
    for(auto &i : req){
        while(p < n && b[p] != -1) p++;
        if(p >= n){
            cout << "NO\n";
            return;
        }
        b[p] = i;
    }

    st.clear();
    for(auto &i : b) st.insert(i);

    if(st.size() != n || *st.begin() != 1 || *st.rbegin() != n){
        cout << "NO\n";
        return;
    }


    vector<uint64_t> H(n + 1);
    for (int i = 1; i <= n; i++)
        H[i] = rng();


    uint64_t ha = 0, hb = 0;

    for (int i = 0; i < k; i++) {
        ha += H[a[i]];
        hb += H[b[i]];
    }

    if (ha != hb) {
        cout << "NO\n";
        return;
    }

    for (int i = k; i < n; i++) {
        ha -= H[a[i-k]];
        hb -= H[b[i-k]];
    
        ha += H[a[i]];
        hb += H[b[i]];
    
        if (ha != hb) {
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