#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){
    int n;
    cin >> n;
    int a[2][n];
    for(auto &i : a){
        for(auto &ele : i) cin >> ele;
    }

    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        int temp = a[0][i] + a[1][i];
        for(int j = 0; j < n; j++){
            if(j != i) temp += max(a[0][j],a[1][j]);
        }
        ans = max(ans,temp);
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