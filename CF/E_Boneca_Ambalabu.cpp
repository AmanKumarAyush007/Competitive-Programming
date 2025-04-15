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

    vector<int> bit(32,0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 32; j++){
            if((1LL << j) & a[i]) bit[j]++;
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        vector<int> temp = bit;

        for(int j = 0; j < 32; j++){
            if((1LL << j) & a[i]) temp[j] = n - temp[j];
        }

        int sum = 0;
        for(int j = 0; j < 32; j++){
            sum += temp[j] * (1LL << j);
        }

        ans = max(ans,sum);
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