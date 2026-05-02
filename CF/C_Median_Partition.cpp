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
#define inf              (int)1e18
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());



void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    inp(v);

    vector<int> a = v;
    sort(all(a));

    int med = a[n/2];

    vector<int> dp(n, -n), more(n,0), less(n,0), equal(n,0);

    for(int i = 0; i < n; i++){
        more[i] = (v[i] > med);
        less[i] = (v[i] < med);
        equal[i] = (v[i] == med);
    } 

    prefixsum(more);
    prefixsum(less);
    prefixsum(equal);

    for(int i = 0; i < n; i++){
        for(int len= 1; len <= n; len+= 2){
            int j = i - (len - 1);

            if(j < 0) break;

            int mr = more[i] - (j-1 >= 0 ? more[j-1] : 0); 
            int ls = less[i] - (j-1 >= 0 ? less[j-1] : 0); 
            int eq = equal[i] - (j-1 >= 0 ? equal[j-1] : 0);
            
            if(eq && abs(mr-ls) <= eq){
                int can = 1 + (j-1 >= 0 ? dp[j-1] : 0);
                dp[i] = max(dp[i], can);
            }
        }
    }


    cout << dp[n-1] << nl;
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