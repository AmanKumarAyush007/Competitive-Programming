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
    int n, k;
    cin >> n >> k;

    vector<string> v(k);
    inp(v);

    vector<set<char>> vs(n);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < k; i++) {
            vs[j].insert(v[i][j]);
        }
    }

    for(int len = 1; len <= n; len++){
        if(n % len) continue;
        bool done = 1;
        for(int i = 0; i < len; i++){
            map<char,int> fre;
            int cnt = 0;
            for(int j = i; j < n; j += len){
                for(auto &ch : vs[j]) fre[ch]++;
                cnt++;
            }


            bool ok = 0;

            for(auto &[chr, val] : fre) {
                if(val == cnt) {
                    ok = 1;
                    break;
                }
            }

            if(ok == 0) {
                done = 0;
                break;
            }
        }
        
        if(done){
            string rep;
            for(int i = 0; i < len; i++){
                map<char,int> fre;
                int cnt = 0;
                for(int j = i; j < n; j += len){
                    for(auto &ch : vs[j]) fre[ch]++;
                    cnt++;
                }
    
                for(auto &[chr, val] : fre) {
                    if(val == cnt) {
                        rep += chr;
                        break;
                    }
                }
                
            }

            string ans;

            while(ans.size() < n){
                ans += rep;
            }

            cout << ans << nl;
            return;
        }
    }


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