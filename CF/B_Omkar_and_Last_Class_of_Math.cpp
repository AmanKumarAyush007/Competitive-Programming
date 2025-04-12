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

    int p = 0;
    for (int m = 2; m <= 100000; ++m) {
        if (n % m == 0) {
            p = m;
            break;
        }
    }
    if (p == 0) {
        p = n;
    }
    cout << n / p << " " << n - (n / p);

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