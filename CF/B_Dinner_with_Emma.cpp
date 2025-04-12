#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,m;
    cin >> n >> m;
    int a[n][m];
    int mx = INT_MIN;
    for(int i = 0; i < n; i++){
        int mn = INT_MAX;
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            mn = min(mn,a[i][j]);
        }
        mx = max(mx,mn);
    }

    cout << mx;

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