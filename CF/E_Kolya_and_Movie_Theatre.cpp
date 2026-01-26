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
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());

vector<int> fn(vector<int>& a, int k) {
    int n = a.size();
    vector<int> dp(n);

    priority_queue<int, vector<int>, greater<int>> pq;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {                  
            pq.push(a[i]);
            curr_sum += a[i];

            if ((int)pq.size() > k) {
                curr_sum -= pq.top();
                pq.pop();
            }
        }
        dp[i] = curr_sum;
    }
    return dp;
}


void solve(){
    int n,m,d;
    cin >> n >> m >> d;
    vector<int> v(n);
    inp(v)

    vector<int> dp = fn(v,m);

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans = max(ans,dp[i] - (d*(i+1)));
    }

    cout << ans << nl;
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