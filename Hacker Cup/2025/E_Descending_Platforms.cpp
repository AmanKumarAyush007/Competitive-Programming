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
#define inp(v)           for(auto& x : v) cin >> x
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x))
#define prefixsum(a)     partial_sum(all(a), (a).begin())
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin())


void solve(){
    int n,m; 
    cin >> n >> m;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<int> v(n+1, 0);
    for(int i = 1; i <= n; i++){
        v[i] = v[i-1] + a[i];
    }

    int bsti = 1;
    long double bst = 0.0L;

    for(int i = 1; i <= n; i++){
        long double rat = (long double)v[i] / i;
        if(rat > bst){
            bst = rat;
            bsti = i;
        }
    }

    vector<int> nonbst;
    for(int i = 1; i <= n; i++){
        if(i != bsti) nonbst.pb(i);
    }

    int l = n * n;
    vector<int> dp(l+1, 0);
    vector<int> from(l+1, -1);

    for(int i : nonbst){
        for(int j = i; j <= l; j++){
            if(dp[j] < dp[j-i] + v[i]){
                dp[j] = dp[j-i] + v[i];
                from[j] = i;
            }
        }
    }

    int bstcst = (int)1e18;
    int bstc = 0;
    int bstk = 0;

    for(int i = 0; i <= l; i++){
        if(dp[i] >= m){
            if(i < bstcst){
                bstcst = i;
                bstc = i;
                bstk = 0;
            }
        } else {
            int rem = m - dp[i];
            int k = (rem + v[bsti] - 1) / v[bsti];
            int totcst = i + k * bsti;
            if(totcst < bstcst){
                bstcst = totcst;
                bstc = i;
                bstk = k;
            }
        }
    }

    vector<int> y(n+1, 0);
    y[bsti] = bstk;

    int c = bstc;
    while(c > 0){
        int i = from[c];
        y[i]++;
        c -= i;
    }

    vector<int> x(n+1, 0);
    x[n] = y[n];
    for(int i = n-1; i >= 1; i--){
        x[i] = y[i] + x[i+1];
    }

    cout << bstcst << nl;
    for(int i = 1; i <= n; i++){
        cout << x[i] << (i == n ? nl : ' ');
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("C:/Users/desktop/Downloads/final/descending_platforms_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
