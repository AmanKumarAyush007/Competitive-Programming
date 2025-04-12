#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x
#define sm(v)      accumulate(all(v),0LL)


void solve(){
    int n;
    cin >> n;
    char c[2][n];
    for(auto &ch : c){
        for(auto &i : ch) cin >> i;
    }
    int ans = 0;
    for(int i = 1; i < n-1; i++){
        if(c[0][i+1] =='x' && c[0][i-1] =='x' && c[0][i] =='.' && c[1][i] == '.' && c[1][i+1] == '.' && c[1][i-1] == '.') ans++;
    }
    // cout << ans;
    for(int i = 1; i < n-1; i++){
        if(c[1][i+1] =='x' && c[1][i-1] =='x' && c[1][i] =='.' && c[0][i] == '.' && c[0][i+1] == '.' && c[0][i-1] == '.') ans++;
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