#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

int sum(vector<int> &v){
    int n = v.size();
    int res = 0;
    for(int i = 0; i < n; i++){
        res += (-1*v[i]*(n-(i+1))) + (v[i]*i);
    }
    return res;
}

void solve(){
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int j = 0; j < m; j++){
        vector<int> v;
        for(int i = 0; i < n; i++){
            v.pb(a[i][j]);
        }
        sort(all(v));
        ans += sum(v);
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