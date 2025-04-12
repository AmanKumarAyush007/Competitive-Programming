#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int m,a,b,c;
    cin >>m >> a >> b >> c;
    int ans = 0;
    ans += min(m,a);
    ans += min(m,b);
    int left = max(0LL,(2*m-ans));
    ans += min(left,c);
    cout<< ans << nl;
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