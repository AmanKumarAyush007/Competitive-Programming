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



void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<string> can = {"00", "10", "11", "01"};

    int ans = 0;
    for(auto &st : can){
        bool ck = 1;
        for(int i = 0; i < min((int)st.size(), n); i++){
            if(s[i] == st[i] || s[i] == '?') continue;
            ck = 0;
            break;
        }
        
        if(ck){
            if(s.size() > 2){
                auto t = st;
                
                for(int i = 2; i < s.size(); i++){
                    if(t[i-2] == s[i]) {
                        ck = 0;
                        break;
                    }
                    t += '0' + (t[i-2] == '0');
                }

                if(ck) ans++;
            }
            else ans++;
        }
    }

    cout << ans << '\n';
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