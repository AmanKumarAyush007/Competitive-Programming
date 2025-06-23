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


void solve(){
    int n; 
    cin >> n;
    vector<int> dp(n+1,1e9);
    dp[0] = 0;
    
    for(int i = 1; i <= n; i++){
        string s = to_string(i);
        for(auto &c : s){
            int dig = c - '0';
            if(dig != 0) dp[i] = min(dp[i-dig]+1,dp[i]);
        }
    }
    
    cout << dp[n] << nl;
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