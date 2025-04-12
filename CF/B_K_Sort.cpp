#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(auto &i : a)cin >> i;
    int mx = 0,pre_mx = 0,diff_mx = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){

      pre_mx = max(a[i],pre_mx);

      int diff = pre_mx - a[i];
      
      ans += diff;
      
      diff_mx = max(diff,diff_mx);

    }
    ans += diff_mx;
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