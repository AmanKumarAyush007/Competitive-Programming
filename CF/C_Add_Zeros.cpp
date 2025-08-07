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

unordered_map<int,vector<int>> graph;

unordered_map<int, int> memo;

int dp(int u) {
    if (!graph.count(u)) return 0;  // base condition

    if (memo.count(u)) return memo[u];  // already found
    
    int mx = 0;

    //compute
    for (int v : graph[u]) {    
        mx = max(mx, v + dp(u + v));
    }

    return memo[u] = mx;    //store and return
}


void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    graph.clear();
    memo.clear();

    for(int i = 1; i < n; i++){
        graph[v[i] + i].pb(i);
    }


    int ans = n + dp(n);
    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
        graph.clear();
    }
    return 0;
}