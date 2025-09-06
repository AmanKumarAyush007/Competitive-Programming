#include<bits/stdc++.h>
using namespace std;

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
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif


const int mod = 1e9 + 7;

void solve(){
    // From Priyansh Aggrawal Yt lecture
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

void solve2(){
    // From Ericto Algorithm
    int n, sum;
    cin >> n >> sum;

    vector<int> v(n), dp(sum+5,0);
    inp(v)

    dp[0] = 1;

    // 2 Ways of writing th loop

    //1st Way -> push dp : here value is pushing towards next possibility
    auto way1 = [&](){
        for(int i = 0; i < sum; i++){
            for(auto &x : v) if(i + x <= sum) dp[i+x] = (dp[i+x] + dp[i]) % mod;
        }
    };

    //2nd Way
    auto way2 = [&](){
        for(int i = 1; i <= sum; i++){
            for(auto &x : v) if(i >= x)dp[i] = (dp[i-x] + dp[i]) % mod;
        }
    };

    way2();

    cout << dp[sum];
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve2();
    }
    return 0;
}