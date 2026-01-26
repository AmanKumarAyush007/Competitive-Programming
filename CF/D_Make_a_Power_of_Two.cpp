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

vector<string> v;

void solve(){
    string s;
    cin >> s;

    int n = s.size();

    int ans = inf;
    
    for(auto &st : v){
        int i = 0, j = 0, taken = 0;
        int m = st.size();

        while(i < n && j < m){
            if(s[i] == st[j]){
                taken++;
                j++;
            }
            i++;
        }

        ans = min(ans, n + m - 2*taken);
    }
    
    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 64; i++){
        int x = 1LL << i;
        v.pb(to_string(x));
    }

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}