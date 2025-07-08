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
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v)

    vector<int> pre_min(n), pre_min_sum(n);
    pre_min[0] = v[0];
    pre_min_sum[0] = v[0];

    for(int i = 1; i < n; i++){
        pre_min[i] = min(v[i],pre_min[i-1]);
        pre_min_sum[i] = pre_min[i] + pre_min_sum[i-1];
    }


    if(n == 2){
        cout << pre_min_sum[n-1] << nl;
        return;
    }

    vector<bool> check(n,false);

    check[2] = (pre_min[1] == pre_min[0]);

    for(int i = 3; i < n; i++){
        check[i] = ((pre_min[i-2] == pre_min[i-1]) || check[i-1]);
    }


    int ans = inf;

    for(int i = 1; i < n; i++){
        int x = pre_min_sum[i]; 
        if(check[i]) x += v[i];
        ans = min(x,ans);
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