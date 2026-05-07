#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)


const int mod = 1e9+7;

void solve(){
    int n;
    cin >> n;

    char grid[n][n];

    for(auto &i : grid){
        for(auto &el : i) cin >> el;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    dp[0][0] = (grid[0][0] == '.');

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i+1 < n && grid[i+1][j] != '*'){
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= mod;
            }
            if(j+1 < n && grid[i][j+1] != '*'){
                dp[i][j+1] += dp[i][j];
                dp[i][j+1] %= mod;
            }
        }
    }


    cout << dp[n-1][n-1] << nl;
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