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
    int a[n];
    int b[m];
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    sort(a,a+n);

    int g = 0;

    for(int i = 1; i < n; i++){
        g = gcd(g,(a[i]-a[0]));
    }
 
    for(int i = 0; i < m; i++){
        int ans = gcd(g,a[0]+b[i]);
        cout << ans << " ";
    }


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