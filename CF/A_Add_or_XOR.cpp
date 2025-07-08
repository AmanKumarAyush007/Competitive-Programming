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
    int a,b,x,y;
    cin >> a >> b >> x >> y;

    if(a == b) cout << 0;
    else if(a > b){

        if(a-b == 1 && (a%2 == 1)) cout << y;
        else cout << -1;
    }
    else{
        int ans = 0;
        while(a != b){
            if(a % 2 == 0) ans += min(x,y);
            else ans += x;
            a++;
        }
        cout << ans;
    }

    
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