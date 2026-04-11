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
    string s;
    cin >> s;

    vector<vector<int>> nxt(n, vector<int>(k,-1));
    vector<int> temp(k,-1);


    for(int i = n-1; i >= 0; i--){
        temp[s[i] - 'a'] = i;
        nxt[i] = temp;
    }

    vector<int> dp(n,0);
    dp[n-1] = 1;

    for(int i = n-2; i >= 0; i--){
        bool done = 0;
        for(int j = 0; j < k; j++){
            if(nxt[i+1][j] == -1){
                dp[i] = 1;
                done = 1;
                break;
            }
        }
        if(!done){
            int mn = inf;
            for(int j = 0; j < k; j++){
                int ind = nxt[i+1][j];
                mn = min(dp[ind], mn);
            }
            dp[i] = mn+1;
        }
    }

    int q;
    cin >> q;

    while(q--){
        string t;
        cin >> t;

        int pos = 0;
        int lst = -1;

        for(char c : t){
            if(pos >= n || nxt[pos][c-'a'] == -1){
                lst = -1;
                break;
            }
            lst = nxt[pos][c-'a'];
            pos = lst + 1;
        }

        if(lst == -1) cout << 0 << nl;
        else cout << dp[lst] << nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}