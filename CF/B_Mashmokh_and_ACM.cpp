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

int dp[2005][2005];
const int mod = 1000000007;

int ways(int n, int k, int i){
    if(k <= 0) return 1;
    if(dp[i][k] != -1) return dp[i][k];

    int ans = 0;

    for(int j = i; j <= n; j += i){
        ans += ways(n,k-1,j) % mod ;
        ans %= mod;
    }
    dp[i][k] = ans;
    return ans;
}

void solve(){
    int n,k;
    cin >> n >> k;

    for(int i = 0; i < 2005; i++){
        for(int j = 0; j < 2005; j++){
            dp[i][j] = -1;
        }
    }

    cout << ways(n,k,1);
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