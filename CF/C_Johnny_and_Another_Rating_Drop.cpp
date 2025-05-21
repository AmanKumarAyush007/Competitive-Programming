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

int po(int n){
    int ans = 0;
    while(n/2) {
        ans++;
        n /= 2;
    }
    return ans;
}


void solve(){
    int n;
    cin >> n;

    int pr = po(n);
    
    int ans = 0;
    for(int i = 1; i <= pr+1; i++){
        ans += i * (((n - ((1LL << (i-1)) - 1)) / (1LL << i)) + (((n - ((1LL << (i-1)) - 1)) % (1LL << i)) != 0));
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