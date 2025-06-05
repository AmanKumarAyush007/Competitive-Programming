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
    int a[n];
    inp(a)

    int cnt = 0;

    int preN[n];

    for(int i = 0; i < n; i++){
        if(a[i] < 0) cnt++;
        preN[i] = cnt;
    }

    vector<pair<int,int>> vp(n);
    int o = 0, e = 0;


    for(int i = n-2; i >= 0; i--){
        if(preN[i+1]&1) o++;
        else e++;
        vp[i] = {e,o};
    }

    int ans = cnt + vp[0].ss;

    for(int i = 1; i < n-1; i++){
        if(preN[i-1]&1) ans += vp[i].ff;
        else ans += vp[i].ss;
    }

    cout << ans << " " << ((n*(n+1))/2) - ans;

    cout << nl;
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