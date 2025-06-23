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
    vector<int> v(n);
    inp(v)

    int dp[n+1];

    dp[n-1] = 1;
    dp[n] = 0;

    for(int i = n-2; i >= 0; i--){
        dp[i] = dp[i+1] + 1;
        if((i + v[i] + 1) <= n) dp[i] = min(dp[i], dp[i + v[i] + 1]);
    }


    cout << dp[0] << nl;
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