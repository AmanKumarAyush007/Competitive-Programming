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
    string s;
    cin >> s;

    if((s.find("101") != string::npos) || (s[0] == '0' && s[1] == '1') || (s[n-1] == '0' && s[n-2] == '1')) {
        cout << "NO\n";
        return;
    }

    vector<int> v(n);

    iota(all(v),1);

    for(int i = 0; i < n; i++){
        while(i+1 < n && s[i] == '0' && s[i+1] == '0') {
            swap(v[i], v[i+1]);
            i++;
        }
    }

    cout << "YES\n";
    for(auto &i : v) cout << i << " ";
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