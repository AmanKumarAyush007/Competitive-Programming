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

    
    auto flip = [&](char c){
        if(c == 'W') return 'B';
        else return 'W';
    };
    
    vector<int> ans;

    auto check = [&](char c){
        ans.clear();
        string t = s;
        for(int i = 0; i < n-1; i++){
            if(t[i] != c){
                t[i] = flip(t[i]);
                t[i+1] = flip(t[i+1]);
                ans.pb(i);
            }
        }
        set<char> st(all(t));

        if(st.size() == 1) return 1;
        else return 0;
    };

    if(check('W') || check('B')){
        cout << ans.size() << nl;
        for(auto &i : ans) cout << i+1 << " " ;
        cout << nl;
    }
    else cout << -1 << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}