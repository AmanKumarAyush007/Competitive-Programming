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

int zer(int n){
    int cnt = 0;
    while(n % 10 == 0){
        cnt++;
        n /= 10;
    }
    return cnt;
}


void solve(){
    int n, k;
    cin >> n >> k;

    pair<int,int> ans = {0,0};
    
    for(int i = 1; i <= k; i++){
        if(zer(n*i) >= ans.ff) ans = {zer(n*i),n*i};
    }
    cout << ans.ss;
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