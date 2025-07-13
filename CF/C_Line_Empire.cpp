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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n+1,0), pre(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    partial_sum(all(v),pre.begin());

    int ans = inf;

    for(int i = 0; i <= n; i++){
        ans = min( ans   , ( ((a+b)*(v[i] - v[0]))   +   (b * ((pre[n] - pre[i]) - ((n-i)*v[i]))) )  );
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