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

const int MOD = 998244353;
string s;
int k, n;
vector<vector<vector<vector<int>>>> dp;

int dfs(int i, int tight, int st, int flag, int mask){
    if(i == n) return (st && flag);
    if(!tight && dp[i][st][flag][mask] != -1)
        return dp[i][st][flag][mask];

    int limit = tight ? (s[i] - '0') : 9;
    int res = 0;

    for(int d = 0; d <= limit; d++){
        int ntight = (tight && d == limit);

        if(!st && d == 0){
            res = (res + dfs(i + 1, ntight, 0, 0, 0)) % MOD;
        }
        else{
            int newMask = 0;
            for(int i = 0; i < k; i++){
                if(mask & (1 << i)){
                    newMask |= (1 << ((i + d) % k));
                }
            }
            newMask |= (1 << (d % k));

            int newFlag = flag || (newMask & 1);

            res = (res + dfs(i + 1, ntight, 1, newFlag, newMask)) % MOD;
        }
    }

    if(!tight) dp[i][st][flag][mask] = res;
    return res;
}


int val(string st){
    s = st;
    n = s.size();
    int m = 1 << k;
    dp.assign(n, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(m, -1))));
    return dfs(0, 1, 0, 0, 0);
}


string conv(string st){
    int i = st.size() - 1;
    while(i >= 0 && st[i] == '0') st[i] = '9', i--;
    if(i >= 0) st[i]--;

    int k = 0;
    while(k + 1 < (int)st.size() && st[k] == '0') k++;
    return st.substr(k);
}

void solve(){
    string l, r;
    cin >> l >> r >> k;

    int rval = val(r);
    int lval = 0;
    if(l != "0") lval = val(conv(l));

    cout << (rval - lval + MOD) % MOD << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("E:/DSA/Hacker Cup/2025/dividing_passcodes_validation_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
