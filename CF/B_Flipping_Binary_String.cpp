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
    string s;
    cin >> s;
    
    int z = count(all(s), '0');
    int o = count(all(s), '1');

    if(o%2 == 1 && z%2 == 0) cout << -1 << nl;
    else{

        int ok1 = false, ok2 = false;
        vector<int> ans1;
        if(o%2 == 0){
            ok1 = 1;
            for(int i = 0; i < n; i++){
                if(s[i] == '1') ans1.pb(i+1);
            }
        }

        vector<int> ans2;
        if(z%2 == 1){
            ok2 = 1;
            for(int i = 0; i < n; i++){
                if(s[i] != '1') ans2.pb(i+1);
            }
        }

        if(ok1 && ok2){
            if(ans1.size() <= ans2.size()){
                cout << ans1.size() << nl;
                for(auto &i : ans1) cout << i << " ";
                if(ans1.size()) cout << nl;
            }
            else {
                cout << ans2.size() << nl;
                for(auto &i : ans2) cout << i << " ";
                if(ans1.size()) cout << nl;
            }
        }
        else if(ok1){
            cout << ans1.size() << nl;
            for(auto &i : ans1) cout << i << " ";
            if(ans2.size()) cout << nl;
        }
        else{
            cout << ans2.size() << nl;
            for(auto &i : ans2) cout << i << " ";
            if(ans2.size()) cout << nl;
        }
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