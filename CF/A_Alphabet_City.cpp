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
    int n,m;
    cin >> n >> m;

    vector<int> tot(26,0);

    vector<vector<int>> req(n, vector<int>(26,0));

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(auto &ch : s) {
            req[i][ch - 'A']++;
            tot[ch - 'A']++;
        }
    }

    for(int i = 0; i < n; i++){
        int ans = m;
        auto need = req[i];

        auto extra = tot;

        for(int j = 0; j < 26; j++){
            extra[j] -= need[j];
        }

        for(int j = 0; j < 26; j++){
            if(tot[j]==0) continue;
            if(extra[j] == 0){
                ans = -1;
                break;
            }
            if((m*extra[j] - need[j]) < 0){
                ans = -1;
                break;
            }
            ans = min(ans, (m*extra[j] - need[j])/extra[j]);
        }

        cout << ans << " ";
    }

    cout << nl;
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