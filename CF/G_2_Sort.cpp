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
    int n,k;
    cin >> n >> k;

    int a[n];
    inp(a);

    vector<int> v(n-1);

    for(int i = 0; i < n-1; i++){
        if(a[i+1]*2 > a[i]) v[i] = 1;
    }

    int sum = 0;

    for(int i = 0; i < k; i++){
        sum += v[i];
    }

    int ans = 0;

    if(sum == k) ans++;

    for(int i = k; i < n-1; i++){
        sum += v[i];
        sum -= v[i - k];
        if(sum == k) ans++;
    }

    cout << ans;
    cout << nl;
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