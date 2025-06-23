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
    int n, x;
    cin >> n >> x;
    int a[n];
    inp(a);

    vector<int> dp(x+1);
    dp[0] = 1;

    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i >= a[j]) dp[i] = (dp[i] + dp[i - a[j]]) % mod;
        }
    }

    cout << dp[x] << nl;
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