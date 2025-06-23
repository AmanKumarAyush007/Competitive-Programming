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

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;

    vector<int> dp(n+1);
    dp[0] = 1;
    
    // status dp[k] -> number of ways to reach sum of k from 0

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i >= j) dp[i] += dp[i - j];
            dp[i] %= mod;
        }
    }

    cout << dp[n];
    cout << nl;
}

void solve1(){
    int n;
    cin >> n;

    vector<int> dp(n+1);
    dp[n] = 1;
    
    // status dp[k] -> number of ways to reach sum of n from k

    for(int i = n-1; i >= 0; i--){
        for(int j = 1; j <= 6; j++){
            if(i + j <= n) dp[i] += dp[i + j];
            dp[i] %= mod;
        }
    }

    cout << dp[0];
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve1();
    }
    return 0;
}