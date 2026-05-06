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

const int N = 1e5+5;
const int mod = 1000000007;
int dp[N][2][2];
int n;
string s, t;

int rec(int i, bool x, bool y){
    if(i >= n) return x&y;

    if(dp[i][x][y] != -1) return dp[i][x][y];

    if(s[i] != '?' && t[i] != '?'){
        if(s[i] > t[i]) dp[i][x][y] = (rec(i+1,1,y));
        else if(s[i] < t[i]) dp[i][x][y] = (rec(i+1,x,1));
        else dp[i][x][y] = (rec(i+1,x,y));
    }
    else{
        dp[i][x][y] = 0;
        if(s[i] == '?' && t[i] == '?'){
            dp[i][x][y] = (dp[i][x][y] + (45*(rec(i+1,1,y))) % mod) % mod;
            dp[i][x][y] = (dp[i][x][y] + (45*(rec(i+1,x,1))) % mod) % mod;
            dp[i][x][y] = (dp[i][x][y] + (10*(rec(i+1,x,y))) % mod) % mod;
        }
        else if(s[i] == '?') {
            int k = t[i] - '0';
            dp[i][x][y] = (dp[i][x][y] + ((9 - k)*(rec(i+1,1,y))) % mod) % mod;
            dp[i][x][y] = (dp[i][x][y] + (k*(rec(i+1,x,1))) % mod) % mod;
            dp[i][x][y] =  (dp[i][x][y] + ((rec(i+1,x,y))) % mod) % mod;
        }
        else if(t[i] == '?') {
            int k = s[i] - '0';
            dp[i][x][y] = (dp[i][x][y] + (k*(rec(i+1,1,y))) % mod) % mod;
            dp[i][x][y] = (dp[i][x][y] + ((9 - k)*(rec(i+1,x,1))) % mod) % mod;
            dp[i][x][y] =  (dp[i][x][y] + ((rec(i+1,x,y))) % mod) % mod;
        }
    }

    return dp[i][x][y];
}

void solve(){
    cin >> n;
    cin >> s >> t;

    memset(dp, -1, sizeof(dp));

    cout << rec(0,0,0) << nl;
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