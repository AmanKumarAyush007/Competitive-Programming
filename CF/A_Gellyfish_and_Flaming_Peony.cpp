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

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

const int N = 5000;

int G[N+1][N+1];

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v)

    int g = 0;
    for(auto &i : v) g = __gcd(g,i);

    int cnt = count(all(v),g);

    if(cnt) cout << n - cnt;
    else{
        vector<int> dp(N+1, 1e9);
        dp[0] = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j <= N; j++){
                int y = G[v[i]][j];
                dp[y] = min(dp[y], (dp[j] + 1));
            }
        }

        cout << dp[g] + n - 2;
    }

    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            G[i][j] = __gcd(i,j);
        }
    }

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}