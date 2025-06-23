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
    int l,n;
    cin >> l >> n;
    int a[l];
    for(auto &i : a) cin >> i;

    vector<int> dp(n+1,1e9);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < l; j++){        
            if(i >= a[j])  dp[i] = min((dp[i - a[j]] + 1), dp[i]);
        }
    }

    cout << (dp[n] == 1e9 ? -1 : dp[n]) << nl;
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