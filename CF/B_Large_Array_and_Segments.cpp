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
    int n,k,x;
    cin >> n >> k >> x;
    vector<int> v(n);
    for(auto &i : v) cin >> i;

    int ans = n*k;

    int tot = sm(v);

    int sum = 0;

    if(tot <= x){
        int time = x/tot;
        if(time <= k) {
            if(x%tot == 0) time--;
            ans -= time*n;
            x -= tot*time;
            k -= time;
        }
        else {
            k = 0;
            ans = 0;
        }    
    }

    if(k > 0){
        int j = n-1;
        while(j >= 0 && sum + v[j] < x){
            sum += v[j];
            ans--;
            j--;    
        }
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