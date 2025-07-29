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
#define lg(x)      (63 - __builtin_clzll(x)) //log base 2


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif


map<int,int> mp;
vector<int> dp(1e5 + 5,-1);



int rec(int i){
    if(i <= 0) return 0;
    if(i == 1) return mp[i];

    if(dp[i] != -1) return dp[i];

    return dp[i] = max(rec(i-1) , rec(i-2) + (i * mp[i]));
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v)

    mp.clear();

    for(auto &i : v) mp[i]++;

    int x = *max_element(all(v));

    cout << rec(x) << nl;
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