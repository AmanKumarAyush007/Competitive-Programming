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
    int n, m;
    cin >> n >> m;

    vector<int> freq(m + 1);

    int tot = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tot += x;
        freq[x]++;
    }

    debug(tot);

    vector<int> ans;
    int curr = 0;

    while(freq[1] != tot){
        if(ans.size() == m) break;


        vector<int> suff(m + 2);
    
        for (int x = m; x >= 1; x--) {
            suff[x] = suff[x + 1] + freq[x];
        }

        int tx = 0;
    
        for (int x = 1; x <= m; x++) {
            int val = suff[x] + (2 * x <= m ? freq[2 * x] : 0);
            debug(val);
            if(val > curr) {
                curr = max(curr, val);
                tx = x;
            }
        }
        debug(tx);
        debug(freq);
        debug(curr);
        
        
        for(int i = tx+1; i <= m; i++){
            freq[tx] += freq[i];
            freq[tx-i] += freq[i];
            freq[i] = 0;
        }
        
        debug(freq);
        debug(curr);

        break;

        ans.pb(curr);
    }

    while(ans.size() < m) ans.pb(curr);


    for(auto &i : ans) cout << i << ' ';
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